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

int f[10111000];

int next(int u) {
    int res = 0;
    while (u) {
        res += sqr(u%10);
        u /= 10;
    }
    return res;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    memset(f, -1, sizeof f);
    int res = 0;
    DEBUG(next(44));
    FOR(i,1,1000 * 10000) {
        if (f[i] < 0) {
            int u = i;
            while (u != 1 && u != 89) {
                u = next(u);
            }
            if (u == 1) f[i] = 1;
            else f[i] = 2;

            u = i;
            while (u != 1 && u != 89) {
                f[u] = f[i];
                u = next(u);
            }
        }
        if (f[i] == 2) ++res;
    }
    DEBUG(res);
    return 0;
}

