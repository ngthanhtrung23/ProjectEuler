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

const int MN = 100 * 1000 * 1000;
long long sieve[MN + 5], f[MN + 5];

void init() {
    for(int i = 2; i*i <= MN; ++i) if (!sieve[i]) {
        int j = i*i;
        while (j <= MN) {
            sieve[j] = i;
            j += i;
        }
    }
    FOR(i,1,MN) {
        if (i == 1) f[i] = 1;
        else if (!sieve[i]) f[i] = i + 1;
        else {
            int p = sieve[i];
            long long pk = 1;
            int u = i;
            while (u % p == 0) {
                u /= p;
                pk *= p;
            }
            if (u == 1) f[i] = (pk * p - 1LL) / (p - 1);
            else f[i] = f[u] * f[pk];
        }
    }
    FOR(i,2,MN) f[i] += f[i-1];
}

long long suma(long long k) {
    return f[k];
    long long res = 0;
    FOR(a,1,k) {
        int cnt = k / a;
        res += cnt * (long long) a;
    }
    return res;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    init();
    cout << "DONE INIT" << endl;

    // a*(x + yi) * b*(x - yi)
    // a*b * (x^2 + y^2)
    //
    // Duyệt x, y --> a*b <= k
    // --> Cần tính tổng a với a*b <= k

    const int n = 100 * 1000 * 1000;
    long long res = 0;
    for(int x = 1; x*x <= n; ++x) {
        for(int y = 0; x*x + y*y <= n; ++y)
        if (__gcd(x, y) == 1) {
            long long cur = suma(n / (x*x + y*y)) * x;
            if (y) cur *= 2LL;
            res += cur;
        }
        if (x % 1000 == 0) DEBUG(x);
    }
    DEBUG(res);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

