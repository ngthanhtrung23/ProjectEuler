#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
using namespace std;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator + (Point a) { return Point(x+a.x, y+a.y); }
    Point operator - (Point a) { return Point(x-a.x, y-a.y); }
    Point operator * (double k) { return Point(x*k, y*k); }
    Point operator / (double k) { return Point(x/k, y/k); }
};
const double EPS = 1e-6;
int cmp(double a, double b) {
    if (fabs(a - b) < EPS) return 0;
    else if (a < b) return -1;
    else return 1;
}
bool operator == (const Point& a, const Point& b) {
    return cmp(a.x, b.x) == 0 && cmp(a.y, b.y) == 0;
}

bool outside(Point P) {
    return -0.01 <= P.x && P.x <= 0.01 && P.y > 0;
}

struct Line {
    double a, b, c;

    Line(Point A, Point B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = - (a * A.x + b * A.y);
    }
    Line(double a, double b, double c) : a(a), b(b), c(c) {}
};

Line tangent(Point P) {
    double slope = -4 * P.x / P.y;
    return Line(slope, -1, P.y - P.x * slope);
}

pair<Point, Point> getPoints(Line l) {
    if (cmp(l.b, 0) == 0) {
        double x = - l.c / l.a;
        return make_pair(Point(x, 20), Point(x, 30));
    }
    else {
        double x1 = 10, x2 = 15;
        double y1 = (-l.c - l.a * x1) / l.b;
        double y2 = (-l.c - l.a * x2) / l.b;
        return make_pair(Point(x1, y1), Point(x2, y2));
    }
}

bool areParallel(Line l1, Line l2) {
    return cmp(l1.a*l2.b, l1.b*l2.a) == 0;
}

bool areIntersect(Line l1, Line l2, Point &p) {
    if (areParallel(l1, l2)) return false;
    double dx = l1.b*l2.c - l2.b*l1.c;
    double dy = l1.c*l2.a - l2.c*l1.a;
    double d  = l1.a*l2.b - l2.a*l1.b;
    p = Point(dx/d, dy/d);
    return true;
}
void closestPoint(Line l, Point p, Point &ans) {
    if (fabs(l.b) < EPS) {
        ans.x = -(l.c) / l.a; ans.y = p.y;
        return;
    }
    if (fabs(l.a) < EPS) {
        ans.x = p.x; ans.y = -(l.c) / l.b;
        return;
    }
    Line perp(l.b, -l.a, - (l.b*p.x - l.a*p.y));
    areIntersect(l, perp, ans);
}
void reflectionPoint(Line l, Point p, Point &ans) {
    Point b;
    closestPoint(l, p, b);
    ans = p + (b - p) * 2;
}

Point cutEllipse(Line l, Point cur) {
    double a = 4*l.b*l.b + l.a*l.a;
    double b = 2*l.a*l.c;
    double c = l.c*l.c - 100*l.b*l.b;

    double delta = b*b - 4*a*c;
    assert(delta >= -EPS);

    double x = (-b + sqrt(delta)) / 2 / a;
    double y = (-l.c - l.a*x) / l.b;
    if (cur == Point(x, y)) {
        x = (-b - sqrt(delta)) / 2 / a;
        y = (-l.c - l.a*x) / l.b;
    }
    return Point(x, y);
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    Point from(0, 10.1);
    Point to (1.4, -9.6);
    int res = 1;
    while (!outside(to)) {
        Line l (from, to);
        cout << "Current: " << endl;
        cout << "From: " << from.x << ' ' << from.y << endl;
        cout << "To:   " << to.x << ' ' << to.y << endl;
        cout << "Line: " << l.a << ' ' << l.b << ' ' << l.c << endl;
        Line m = tangent(to);
        auto cur = getPoints(l);
        auto next = cur;
        reflectionPoint(m, cur.first, next.first);
        reflectionPoint(m, cur.second, next.second);

        Line k (next.first, next.second);
        cout << "Reflection: " << endl;
        cout << "Line: " << k.a << ' ' << k.b << ' ' << k.c << endl;
        cout << "From: " << to.x << ' ' << to.y << endl;
        Point go = cutEllipse(k, to);
        cout << "To:   " << go.x << ' ' << go.y << endl;

        cout << go.x << ' ' << go.y << endl;

        from = to;
        to = go;
        ++res;
        if (res == 3) break;
    }

    DEBUG(res);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

