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

int c[1011][1011], f[1011];

map<long long, long long> cache;

long long get(long long n) {
    if (cache.count(n)) return cache[n];

    if (n <= 7) return cache[n] = n * (n+1LL) / 2;
    long long p7 = 1;
    while (p7 * 7LL < n) p7 *= 7;

    long long res = 0;
    for(long long x = p7; x < n + p7; x += p7) {
        long long bottom = min(n, x);
        long long mult = x / p7;
        long long nn = bottom % p7; if (nn == 0) nn = p7;

        res += mult * get(nn);
    }
    return cache[n] = res;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    FOR(i,0,1000) {
        c[i][0] = 1;
        FOR(j,1,i)
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % 7;

        FOR(j,0,i) if (c[i][j]) ++f[i];
        if (i) f[i] += f[i-1];
    }
    PR(f, 10);
    FOR(i,1,1000) {
        assert(f[i-1] == get(i));
    }
    DEBUG(get(1000 * 1000 * 1000));
    return 0;
}

