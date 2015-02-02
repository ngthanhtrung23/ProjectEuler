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

const int MN = 2000;
const long long MOD = 1000 * 1000 * 1000;

bool good[MN];
long long f[22][MN], p10[22], cnt[22][MN];

void add(long long& x, long long val) {
    x = (x + val) % MOD;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,1,100) if (i*i < 2000) good[i*i] = true;
    p10[0] = 1;
    FOR(i,1,20) p10[i] = (p10[i-1] * 10LL) % MOD;

    f[0][0] = 0;
    cnt[0][0] = 1;
    FOR(i,0,19) REP(sum,MN) if (cnt[i][sum]) REP(cur,10) {
        int newSum = sum + cur*cur;
        add(cnt[i+1][newSum], cnt[i][sum]);
        add(f[i+1][newSum], f[i][sum] + cnt[i][sum] * p10[i] * cur);
    }
    long long res = 0;
    REP(sum,MN)
        if (good[sum])
            add(res, f[20][sum]);

    DEBUG(res);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

