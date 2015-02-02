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

const int MN = 1000111;
int sieve[MN];

// R(10^9) % p == 0
// 9*R(10^9) + 1 == 10^(10^9 + 1)
// R(10^9) == 0 mod p
// 9*R(10^9) + 1 == 1 mod p
// 10^(10^9) == 1 mod p

long long power(long long x, int k, long long p) {
    if (k == 0) return 1 % p;
    if (k == 1) return x % p;
    long long mid = power(x * x % p, k >> 1, p);
    if (k & 1) return mid * x % p;
    else return mid;
}

int f(int n) {
    if (power(10, 1000000000, n) != 1) return -1;

    int i = 1, mult = 1;

    while (n > 1) {
        int p = (sieve[n]) ? sieve[n] : n;
        i *= p;
        n /= p;

        while (n % p == 0) {
            mult *= p;
            n /= p;
        }
    }

    int rem = 0;
    unordered_set<int> all;
    FOR(t,1,1000 * 1000 * 1000) {
        rem = (rem * 10 + 1) % i;
        if (all.count(rem)) return -1;
        all.insert(rem);
        if (rem == 0) return t * mult;
    }
    all.clear();
    return -1;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    
    FOR(i,2,1000) if (!sieve[i]) {
        int j = i*i;
        while (j < MN) {
            sieve[j] = i;
            j += i;
        }
    }

    const int oo = 1000 * 1000 * 1000;
    int cnt = 0, sum = 0;
    FOR(i,2,MN-1) if (!sieve[i]) {
        int cur = f(i);
        if (cur > 0 && oo % cur == 0) {
            cnt += 1;
            sum += i;
            cout << cnt << ' ' << i << ' ' << sum << endl;
            if (cnt == 40) break;
        }
    }

    return 0;
}

