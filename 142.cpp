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

const int oo = 2000;

bool isSquare(long long n) {
    long long x = (int) sqrt(n) - 5;
    while (x * x < n) ++x;
    return x*x == n;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    int res = 1000111000;
    FOR(e,1,oo) for(int f = e+2; f < oo; f += 2) {
        int e2 = e*e, f2 = f*f;
        int x = (e2 + f2) / 2;
        int z = (f2 - e2) / 2;

        if (x <= z || z <= 0) continue;

        FOR(d,1,f-1) {
            int d2 = d*d;
            int c2 = e2 - f2 + d2;
            if (c2 < 0 || (c2 + d2) % 2) continue;

            int y = (c2 + d2) / 2;
            if (x <= y || y <= z) continue;
            if (isSquare(x+y) && isSquare(x-y) && isSquare(y+z) && isSquare(y-z) && x + y + z < res) {
                res = min(res, x + y + z);
                DEBUG(x);
                DEBUG(y);
                DEBUG(z);
            }
        }
    }
    DEBUG(res);
    return 0;
}

