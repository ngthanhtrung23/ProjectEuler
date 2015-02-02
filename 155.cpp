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

int main() {
    clock_t startTime = clock();
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    set< Fraction > val[20];
    val[1].insert(Fraction(1, 1));
    FOR(i,2,18) {
        FOR(left,1,i-1) {
            int right = i - left;
            if (right < left) continue;
            for(auto a : val[left])
                for(auto b : val[right]) {
                    val[i].insert(a + b);
                    val[i].insert( (a*b) / (a + b) );
                }
        }
        cout << i << ' ' << val[i].size() << endl;
    }
    set<Fraction> all;
    FOR(i,1,18) {
        for(auto f : val[i])
            all.insert(f);
    }
    DEBUG(all.size());
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

