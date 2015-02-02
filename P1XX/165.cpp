#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
using namespace std;

ll s[20111], t[20111];

struct Fraction {
    ll x, y;

    Fraction() { x = 0, y = 1; }
    Fraction(ll _x, ll _y) {
        if (_y == 0) {
            cout << "Invalid fraction: " << _x << '/' << _y << endl;
        }
        ll g = __gcd(_x, _y);
        x = _x / g;
        y = _y / g;
        if (y < 0) {
            x = -x;
            y = -y;
        }
    }

    friend ostream& operator << (ostream& cout, const Fraction& a) {
        cout << a.x << '/' << a.y;
        return cout;
    }
};
Fraction operator + (const Fraction& a, const Fraction& b) {
    return Fraction(a.x*b.y + a.y*b.x, a.y*b.y);
}
Fraction operator - (const Fraction& a, const Fraction& b) {
    return Fraction(a.x*b.y - a.y*b.x, a.y*b.y);
}
Fraction operator * (const Fraction& a, const Fraction& b) {
    return Fraction(a.x*b.x, a.y*b.y);
}
Fraction operator / (const Fraction& a, const Fraction& b) {
    return Fraction(a.x*b.y, a.y*b.x);
}

bool operator < (const Fraction& a, const Fraction& b) {
    return a.x*b.y < a.y*b.x;
}
bool operator == (const Fraction& a, const Fraction& b) {
    return a.x*b.y == a.y*b.x;
}
struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}

    Point operator - (Point a) { return Point(x-a.x, y-a.y); }
};
int ccw(Point a, Point b, Point c) {
    b = b - a; c = c - a;
    long long t = b.x*c.y - b.y*c.x;
    if (t == 0) return 0;
    else if (t < 0) return -1;
    else return 1;
}

struct Line {
    ll a, b, c;
    Point P, Q;

    Line() {}
    Line(Point P, Point Q) : P(P), Q(Q) {
        a = Q.y - P.y;
        b = P.x - Q.x;
        c = - (a * P.x + b * P.y);
    }
} l[5011];

bool intersect(const Line& a, const Line& b) {
    return ccw(a.P, a.Q, b.P) * ccw(a.P, a.Q, b.Q) < 0
        && ccw(b.P, b.Q, a.P) * ccw(b.P, b.Q, a.Q) < 0;
}

pair< Fraction, Fraction> cut(const Line& x, const Line& y) {
    ll d  = x.a*y.b - x.b*y.a;
    ll dx = x.b*y.c - x.c*y.b;
    ll dy = x.c*y.a - x.a*y.c;
    return make_pair( Fraction(dx, d), Fraction(dy, d));
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    s[0] = 290797;
    FOR(i,1,20000) {
        s[i] = s[i-1] * s[i-1] % 50515093;
        t[i] = s[i] % 500;
    }
    PR(t, 4);
    int nl = 0;
    for(int i = 1; i <= 20000; i += 4) {
        l[++nl] = Line(Point(t[i], t[i+1]), Point(t[i+2], t[i+3]));
    }
    cout << "Generated " << nl << " lines" << endl;
    set< pair<Fraction, Fraction> > s;
    FOR(i,1,nl) {
        FOR(j,i+1,nl) if (intersect(l[i], l[j])) {
            auto x = cut(l[i], l[j]);
            s.insert(x);
        }
        if (i % 50 == 0) DEBUG(i);
    }
    DEBUG(s.size());

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

