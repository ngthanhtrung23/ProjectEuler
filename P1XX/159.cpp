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

long long f[1000 * 1000 + 5];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    long long res = 0;
    f[1] = 0;
    FOR(i,2,1000 * 1000 - 1) {
        f[i] = i % 9; if (!f[i]) f[i] = 9;
        for(int j = 2; j*j <= i; ++j) if (i % j == 0) {
            f[i] = max(f[i], f[j] + f[i/j]);
        }
        res += f[i];
    }
    DEBUG(res);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

