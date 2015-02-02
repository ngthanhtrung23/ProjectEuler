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

#define TWO(X) (1<<(X))
#define CONTAIN(S,X) (S & TWO(X))

long long f[TWO(20)][2][20], c[33][33];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,0,30) {
        c[i][0] = 1;
        FOR(j,1,i) c[i][j] = c[i-1][j-1] + c[i-1][j];
    }

    long long res = 0;
    FOR(len,3,18) {
        memset(f, 0, sizeof f);

        REP(i,len) f[TWO(i)][0][i] = 1;
        REP(mask,TWO(len)-1) REP(t,2) REP(last,len)
            if (f[mask][t][last])
                REP(cur,len)
                    if (!CONTAIN(mask,cur)) {
                        if (cur < last)
                            f[mask + TWO(cur)][t][cur] += f[mask][t][last];

                        if (cur > last && t == 0)
                            f[mask + TWO(cur)][1][cur] += f[mask][t][last];
                    }

        long long cur = 0;
        REP(last,len)
            cur += f[TWO(len)-1][1][last];
        cur *= c[26][len];

        cout << len << ' ' << cur << endl;
        res = max(res, cur);
    }
    DEBUG(res);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

