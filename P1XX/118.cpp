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
int a[11];
map<int,int> f[11];
int sieve[MN];

void init() {
    FOR(i,2,2000) if (sieve[i] == 0) {
        for(int j = i*i; j < MN; j += i)
            sieve[j] = i;
    }
    sieve[1] = 1;
}

typedef long long ll;

ll powMod(ll x, ll k, ll m) {
  if (k == 0)      return 1;
  if ((k & 1))     return x*powMod(x, k-1, m) % m;
  else                return powMod(x*x % m, k/2, m);
}

bool suspect(ll a, ll s, ll d, ll n) {
    ll x = powMod(a, d, n);
    if (x == 1) return true;
    for (int r = 0; r < s; ++r) {
        if (x == n - 1) return true;
        x = x * x % n;
    }
    return false;
}
// {2,7,61,-1}                      is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^16 (at least)
bool isPrime(ll n) {
    if (n < MN) return sieve[n] == 0;
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    ll test[] = {2,3,5,7,11,13,17,19,23,-1};
    ll d = n - 1, s = 0;
    while (d % 2 == 0) ++s, d /= 2;
    for (int i = 0; test[i] < n && test[i] != -1; ++i)
        if (!suspect(test[i], s, d, n)) return false;
    return true;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    FOR(i,1,9) a[i] = i;
    ll res = 0;
    init();
    do {
        FOR(i,0,9)
            f[i].clear();

        f[0][1] = 1;
        FOR(i,1,9) {
            FOR(last,0,i-1) {
                ll n = 0;
                FOR(t,last+1,i) n = n * 10 + a[t];
                if (!isPrime(n)) continue;

                for(auto x : f[last]) {
                    if (x.first < n)
                        f[i][n] += x.second;
                }
            }
        }
        for(auto x : f[9])
            res += x.second;
    } while (next_permutation(a+1, a+10));
    DEBUG(res);
    return 0;
}

