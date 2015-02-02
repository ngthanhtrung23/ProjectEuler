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

typedef long long ll;

ll mulMod(ll x, ll y, ll p) {
    if (x < 1000111000111000111LL / y) return x * y % p;
    ll mid = mulMod((x+x)%p, y>>1LL, p);
    if (y & 1) return (mid + x) % p;
    else return mid;
}
ll powMod(ll x, ll k, ll m) {
    if (k == 0) return 1;
    if ((k & 1)) return mulMod(x,powMod(x, k-1, m), m);
    else return powMod(mulMod(x,x,m), k/2, m);
}
bool suspect(ll a, ll s, ll d, ll n) {
    ll x = powMod(a, d, n);
    if (x == 1) return true;
    for (int r = 0; r < s; ++r) {
        if (x == n - 1) return true;
        x = mulMod(x, x, n);
    }
    return false;
}
bool slowIsPrime(ll n) {
    for(ll i = 2; i*i <= n; ++i)
        if (n % i == 0) {
            return false;
        }
    return n > 1;
}

// {2,7,61,-1}                      is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
bool isPrime(ll n) {
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    ll test[] = {2,3,5,7,11,13,17,19,23,-1};
    ll d = n - 1, s = 0;
    while (d % 2 == 0) ++s, d /= 2;
    for (int i = 0; test[i] < n && test[i] != -1; ++i)
        if (!suspect(test[i], s, d, n)) {
            if (n == 6380019256901LL) {
                DEBUG(n);
                DEBUG(i);
                DEBUG(test[i]);
                DEBUG(s);
                DEBUG(d);
                DEBUG(n);
            }
            return false;
        }
    return true;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    int res = 0;
    long long sum = 0;
//    for(int i = 10; i <= 100000; i += 10) {
//        int t[] = {1, 3, 7, 9, 13, 27};
//        for(int x = 0; x < 6; ++x) {
//            long long val = i*(long long) i + t[x];
//            assert(isPrime(val) == slowIsPrime(val));
//        }
//    }
    for(long long i = 10; i < 150ll * 1000000; i += 10) {
        if (i % 3) {
            int m7 = i % 7;
            if (m7 == 3 || m7 == 4) {
                long long ii = i*i;
                if (i == 2525870) {
                    DEBUG(ii);
                    DEBUG(isPrime(ii+1));
                    DEBUG(slowIsPrime(ii+1));
                    DEBUG(isPrime(ii+3));
                    DEBUG(isPrime(ii+7));
                    DEBUG(isPrime(ii+9));
                    DEBUG(isPrime(ii+13));
                    DEBUG(isPrime(ii+27));
                }
                if (isPrime(ii+1) && isPrime(ii+3) && isPrime(ii+7) && isPrime(ii+9)
                        && isPrime(ii+13) && isPrime(ii+27)
                        ) {
                    DEBUG(i);
                    res ++;
                    sum += i;
                }
            }
        }
    }
    DEBUG(res);
    DEBUG(sum);
    return 0;
}

