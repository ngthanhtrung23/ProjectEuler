#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }

#define sqr(x) ((x) * (x))
using namespace std;

bool good[1000111];
int sieve[1000111];

void init() {
    for(int i = 2; i <= 1000; ++i) if (!sieve[i]) {
        int j = i*i;
        while (j < 1000111) {
            sieve[j] = i;
            j += i;
        }
    }
}

int p[111], k[111], cnt, np;
unordered_map<long long,int> squareRoot;

void attempt(int i, long long a0, long long a1, long long t) {
    if (i > np) {
        long long xx = (t + a0 * a0) / a0;
        if (squareRoot.count(xx)) {
            good[squareRoot[xx]] = true;
            ++cnt;
            cout << cnt << ": " << squareRoot[xx] << ' ' << a0 << ' ' << a1 << endl;
        }
        return ;
    }

    for(long long x = 0, power = 1; x <= k[i] + k[i]; ++x, power *= p[i]) {
        if (a0 * power > a1) break;
        attempt(i+1, a0 * power, a1, t);
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,1,1000000) squareRoot[i * (long long) i] = i;

    init();

    // n = d*q + r == x^2
    // r < d --> 3 cases
    // 1. q < r < d
    // 2. r < q < d
    // 3. r < d < q
    //
    // geometric sequence --> a0, a0*u/v, a0*u^2 / v^2 (u >= v, gcd(u, v) == 1)
    // 1. a0^2 * u^2 / v^2   +  a0 * u / v == x^2
    // 2. a0^2 * u^3 / v^3   +  a0 == x^2
    // 3. a0^2 * u^3 / v^3   +  a0 == x^2

    // Case 1:
    // k^2 + k == x^2 --> 0 solution

    // Case 2 & 3:
    // a0^2 * u^3 / v^3 + a0 == x^2
    // a0^3 * u^3 / v^3 + a0^2 == x^2 * a0
    // a1^3 + a0^2 == x^2 * a0
    //
    // t = a0 * (x*x - a0) = k^3

    cnt = 0;
    for(long long a1 = 2; a1 < 1000000; ++a1) {
        long long t = a1 * a1 * a1;
        np = 0;

        int u = a1;
        while (u > 1) {
            int cur = (sieve[u]) ? sieve[u] : u;
            ++np;
            p[np] = cur;
            k[np] = 0;
            while (u % cur == 0) {
                u /= cur;
                ++k[np];
            }
        }

        attempt(1, 1, a1, t);
    }

    long long res = 0;
    FOR(i,1,1000) if (i*i < 100000 && good[i]) res += i * (long long) i;
    DEBUG(res);
    assert(res == 124657);

    res = 0;
    FOR(i,1,999999) if (good[i]) res += i * (long long) i;
    DEBUG(res);
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

