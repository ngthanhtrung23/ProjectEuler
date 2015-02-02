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

long long p2[11], p5[11], p10[11];

long long solve(long long n, long long u, long long v) {
    long long prod = p10[n] / u / v * (u + v);

    long long res = 0;
    for(long long i = 1; i*i <= prod; ++i)
        if (prod % i == 0) {
            res++;
            if (i * i != prod) {
                res++;
            }
        }
    return res;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    // 1/a + 1/b == p/10^n
    // 10^n * (a + b) = p*a*b
    //
    // Let d = gcd(a, b), a = d*u, b = d*v
    //
    // Then,
    // 10^n * (u+v) == p*d*u*v
    //
    // Since gcd(u, v) == 1, 10^n must be divisible by u*v
    //
    // Thus, we have:
    // (u, v) is in {(1, 1), (1, 2^x), (1, 5^x), (1, 2^x * 5^y), (2^x, 5^y)}


    p2[0] = 1; FOR(i,1,10) p2[i] = p2[i-1] * 2LL;
    p5[0] = 1; FOR(i,1,10) p5[i] = p5[i-1] * 5LL;
    p10[0] = 1; FOR(i,1,10) p10[i] = p10[i-1] * 10LL;

    long long res = 0;
    FOR(n,1,9) {
        long long cur = 0;
        cur += solve(n, 1, 1);
        
        FOR(x,1,n) cur += solve(n, 1, p2[x]);
        FOR(x,1,n) cur += solve(n, 1, p5[x]);
        FOR(x,1,n) FOR(y,1,n) cur += solve(n, 1, p2[x] * p5[y]);

        FOR(x,1,n) FOR(y,1,n) cur += solve(n, p2[x], p5[y]);

        cout << n << ": " << cur << endl;
        res += cur;
    }
    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

