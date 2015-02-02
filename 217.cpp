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

const long long MOD = 14348907;

long long p10[55];
long long f[55][1011], cnt[55][1011];

void add(long long& x, long long val) {
    if (x < 0) x = 0;
    x = (x + val) % MOD;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    p10[0] = 1; FOR(i,1,50) p10[i] = p10[i-1] * 10LL % MOD;

    long long sum = 0;

    FOR(x,1,9) FOR(y,0,9) {
        sum += x * 100 + y * 10 + x;
    }
    DEBUG(sum);

    sum = 0;
    FOR(x,1,9) FOR(y,0,9) FOR(z,0,9) FOR(t,0,9) {
        if (x + y == z + t)
            sum += x * 1000 + y * 100 + z * 10 + t;
    }
    DEBUG(sum);

    long long res = 0;
    FOR(len,1,47) {
        int bound = len / 2 + len % 2;

        memset(f, 0, sizeof f);
        memset(cnt, 0, sizeof cnt);
        f[0][500] = 0;
        cnt[0][500] = 1;

        FOR(i,1,bound) FOR(diff,0,1000) if (cnt[i-1][diff] > 0) {
            int left = len - i + 1, right = i;
            REP(x,10) if (i > 1 || x > 0)
                REP(y,10)
                    if (x == y || len % 2 == 0 || i < bound) {
                        long long g = y * p10[right - 1];
                        if (i == bound && len % 2 == 1) g = 0;

                        add(cnt[i][diff + x - y], cnt[i-1][diff]);
                        add(f[i][diff + x - y], f[i-1][diff] + (x * p10[left-1] + g) * cnt[i-1][diff]);
                    }
        }

        add(res, f[bound][500]);
        if (len <= 5) cout << len << ' ' << f[bound][500] << ' ' << res << endl;
    }
    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

