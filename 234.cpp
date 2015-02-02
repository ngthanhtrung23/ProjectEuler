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

const long long INF = 999966663333LL;

long long first_divisible(long long x, long long a) {
    if (x % a == 0) return x;
    return x - (x % a) + a;
}

long long last_divisible(long long x, long long a) {
    if (x % a == 0) return x;
    return x - x % a;
}

long long sum_divisible(long long l, long long r, long long a) {
    l = first_divisible(l, a);
    r = last_divisible(r, a);
    if (l > r) return 0;

    // l + (l + a) + (l + 2a) + ... + l + (cnt - 1) * a
    long long cnt = (r - l) / a + 1;
    return cnt * l + a * cnt * (cnt - 1LL) / 2;
}

long long lcm(long long x, long long y) {
    return x / __gcd(x, y) * y;
}

long long get(long long lb, long long ub, long long a, long long b) {
    return sum_divisible(lb, ub, a)
            + sum_divisible(lb, ub, b)
            - 2 * sum_divisible(lb, ub, lcm(a, b));
}

const int MN = 1000111;
int sieve[MN];
long long primes[MN], nPrime;

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    for(int i = 2; i <= 2000; ++i) if (!sieve[i]) {
        for(int j = i*i; j < MN; j += i)
            sieve[j] = i;
    }
    for(int i = 2; i < MN; ++i)
        if (!sieve[i])
            primes[++nPrime] = i;

    long long res = 0;
    for(int root = 1; primes[root] * primes[root] <= INF; ++root) {
        long long lb = primes[root] * primes[root] + 1;
        long long ub = min(primes[root+1] * primes[root+1] - 1, INF);

        res += get(lb, ub, primes[root], primes[root + 1]);
        cout << root << " --> " << res << endl;
    }
    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

