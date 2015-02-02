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

#define EPS 1e-3

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

inline int cmp(double a, double b) {
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point {
    double x, y;
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point operator + (Point a) { return Point(x+a.x, y+a.y); }
    Point operator - (Point a) { return Point(x-a.x, y-a.y); }
    Point operator * (double k) { return Point(x*k, y*k); }
    Point operator / (double k) { return Point(x/k, y/k); }

    double operator * (Point a) { return x*a.x + y*a.y; } // dot product
    double operator % (Point a) { return x*a.y - y*a.x; } // cross product

    int cmp(Point q) const { if (int t = ::cmp(x,q.x)) return t; return ::cmp(y,q.y); }

    #define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
    Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
    #undef Comp

    Point conj() { return Point(x, -y); }
    double norm() { return x*x + y*y; }

    // Note: There are 2 ways for implementing len():
    // 1. sqrt(norm()) --> fast, but inaccurate (produce some values that are of order X^2)
    // 2. hypot(x, y) --> slow, but much more accurate
    double len() { return sqrt(norm()); }

    Point rotate(double alpha) {
        double cosa = cos(alpha), sina = sin(alpha);
        return Point(x * cosa - y * sina, x * sina + y * cosa);
    }

    void print() const {
        cout << x << ' ' << y << endl;
    }
};

int ccw(Point a, Point b, Point c) {
    return cmp((b-a)%(c-a),0);
}

double angle(Point a, Point o, Point b) { // angle AOB
    a = a - o; b = b - o;
    return acos((a * b) / sqrt(a.norm() * b.norm()));
}

// Distance from p to Line ab (closest Point --> c)
double distToLine(Point p, Point a, Point b, Point &c) {
    Point ap = p - a, ab = b - a;
    double u = (ap * ab) / ab.norm();
    c = a + (ab * u);
    return (p-c).len();
}

// Distance from p to segment ab (closest Point --> c)
double distToLineSegment(Point p, Point a, Point b, Point &c) {
    Point ap = p - a, ab = b - a;
    double u = (ap * ab) / ab.norm();
    if (u < 0.0) {
        c = Point(a.x, a.y);
        return (p - a).len();
    }
    if (u > 1.0) {
        c = Point(b.x, b.y);
        return (p - b).len();
    }
    return distToLine(p, a, b, c);
}

// NOTE: WILL NOT WORK WHEN a = b = 0.
struct Line {
    double a, b, c;
    Point A, B; // Added for polygon intersect line. Do not rely on assumption that these are valid

    Line(double a, double b, double c) : a(a), b(b), c(c) {} 

    Line(Point A, Point B) : A(A), B(B) {
        a = B.y - A.y;
        b = A.x - B.x;
        c = - (a * A.x + b * A.y);
    }
    Line(Point P, double m) {
        a = -m; b = 1;
        c = -((a * P.x) + (b * P.y));
    }
    double f(Point A) {
        return a*A.x + b*A.y + c;
    }
};

bool areParallel(Line l1, Line l2) {
    return cmp(l1.a*l2.b, l1.b*l2.a) == 0;
}

bool areSame(Line l1, Line l2) {
    return areParallel(l1 ,l2) && cmp(l1.c*l2.a, l2.c*l1.a) == 0
                && cmp(l1.c*l2.b, l1.b*l2.c) == 0;
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

map<Point,int> id;

vector<Point> base[44];

const int n = 36;
const double half_side = 1;
const double side = half_side * 2;
const double height = sqrt(3.0) * half_side;

// Edges:
//    /  0
//    \\ 1
//    -  2
//    |  3
//    _/ 4
//    \\_ 5

int lab[6][4011];

int getRoot(int t, int u) {
    if (lab[t][u] < 0) return u;
    return lab[t][u] = getRoot(t, lab[t][u]);
}

void merge(int t, int u, int v) {
    u = getRoot(t, u); v = getRoot(t, v);
    if (u == v) return ;

    int x = lab[t][u] + lab[t][v];
    if (lab[t][u] < lab[t][v]) {
        lab[t][u] = x;
        lab[t][v] = u;
    }
    else {
        lab[t][v] = x;
        lab[t][u] = v;
    }
}

int addPoint(Point P) {
    if (id.count(P)) return id[P];
    else {
        int nId = id.size();
        id[P] = nId;
    }
}

void add(int typ, Point A, Point B) {
    merge(typ, id[A], id[B]);
}

void line(int typ, Point A, Point B, Point C) {
    add(typ, A, B);
    add(typ, B, C);
}

int cache[4011][4011];
int ke(int u, int v) {
    if (cache[u][v] >= 0) return cache[u][v];

    REP(t,6)
        if (getRoot(t, u) == getRoot(t, v)) {
            return cache[u][v] = t + 1;
        }
    return cache[u][v] = 0;
}

vector<Point> addTriangle(Point A) {
    Point mid_BC = A - Point(0, height);
    Point B = mid_BC - Point(half_side, 0);
    Point C = mid_BC + Point(half_side, 0);
    Point O = (A + mid_BC * 2) / 3.0;
    Point mid_AB = (A + B) / 2.0;
    Point mid_AC = (A + C) / 2.0;

    addPoint(A);
    addPoint(B);
    addPoint(C);
    addPoint(O);
    addPoint(mid_AB);
    addPoint(mid_BC);
    addPoint(mid_AC);


    line(0, A, mid_AB, B);
    line(1, A, mid_AC, C);
    line(2, B, mid_BC, C);
    line(3, A, O, mid_BC);
    line(4, B, O, mid_AC);
    line(5, C, O, mid_AB);

    return vector<Point> {B, C};
}

// Edges:
//    /  0
//    \\ 1
//    -  2
//    |  3
//    _/ 4
//    \\_ 5

void addReverseTriangle(Point B, Point C) {
    Point mid_BC = (B + C) / 2.0;
    Point A = mid_BC - Point(0, height);
    Point O = (A + mid_BC * 2) / 3.0;
    Point mid_AB = (A + B) / 2.0;
    Point mid_AC = (A + C) / 2.0;

    addPoint(A);
    addPoint(B);
    addPoint(C);
    addPoint(O);
    addPoint(mid_AB);
    addPoint(mid_BC);
    addPoint(mid_AC);

    line(0, C, mid_AC, A);
    line(1, B, mid_AB, A);
    line(2, B, mid_BC, C);
    line(3, A, O, mid_BC);
    line(4, C, O, mid_AB);
    line(5, B, O, mid_AC);
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    memset(lab, -1, sizeof lab);
    memset(cache, -1, sizeof cache);

    base[1] = addTriangle(Point(0, 0));
    FOR(i,2,n) {
        // Tam giac xuoi
        bool first = true;
        for (auto P : base[i-1]) {
            auto cur = addTriangle(P);
            if (first) {
                first = false;
                base[i].push_back(cur[0]);
            }
            base[i].push_back(cur[1]);
        }
        // Tam giac nguoc
        REP(j,base[i-1].size()-1) {
            addReverseTriangle(base[i-1][j], base[i-1][j+1]);
        }
    }
    DEBUG(id.size());

    long long res = 0;
    REP(i,id.size())
        FOR(j,i+1,id.size()-1)
            if (ke(i, j)) {
                FOR(k,j+1,id.size()-1)
                    if (ke(i, k) && ke(j, k)) {
                        if (ke(i, j) != ke(i, k) || ke(i, j) != ke(k, j))
                            ++res;
                    }
            }
    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

