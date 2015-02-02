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

int genPrimitivePytTriples(int n) {
    int res = 0;
    for (int r=1; r*r<=n; ++r) for (int s=(r%2==0)?1:2; s<r; s+=2) if (__gcd(r,s)==1) {
        int xx = r*r - s*s;
        int yy = 2*r*s;
        int zz = r*r + s*s;

        int x = xx, y = yy, z = zz;
        while (x + y + z < 100000000) {
            long long sq = z*(long long)z - 2LL*x*(long long)y;
            long long t = sqrt(sq) - 5; if (t < 0) t = 0;
            while (t*t < sq) ++t;
            if (t*t != sq) {
            }
            else if (z % t == 0) {
                ++res;
            }
            x += xx;
            y += yy;
            z += zz;
        }
    }
    return res;
}
int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    auto r = genPrimitivePytTriples(50000111);
    DEBUG(r);
    return 0;
}

