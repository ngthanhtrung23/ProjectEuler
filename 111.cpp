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
    return ((((x*(y>>20))%p)<<20)%p + x*(y&((1<<20)-1)))%p;
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
// {2,7,61,-1}                      is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,61,-1} is for n < 10^16 (at least)
bool isPrime(ll n) {
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    ll test[] = {2,3,5,7,11,13,17,19,23,27,29,31,61,-1};
    ll d = n - 1, s = 0;
    while (d % 2 == 0) ++s, d /= 2;
    for (int i = 0; test[i] < n && test[i] != -1; ++i)
        if (!suspect(test[i], s, d, n)) return false;
    return true;
}
bool brute(ll n) {
    for(ll i = 2; i*i <= n; ++i)
        if (n % i == 0) {
            return false;
        }
    return true;
}

const int N = 10;

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    ll res = 0;
    FOR(dig,0,9) {
        DEBUG(res);
        ll cur = 0;
        FOR(x,0,9) 
            FOR(pos,0,N-1) {
                string s; while (s.length() < N) s += '0' + dig;
                s[pos] = x + '0';
                if (s[0] == '0') continue;
                stringstream ss; ss << s;
                ll n; ss >> n;
                if (isPrime(n)) {
                    cur += n;
                }
            }
        res += cur;

        if (cur > 0) continue;

        FOR(x,0,9) FOR(y,0,9) {
            FOR(p1,0,N-1) FOR(p2,p1+1,N-1) {
                string s; while (s.length() < N) s += '0' + dig;
                s[p1] = x + '0';
                s[p2] = y + '0';
                if (s[0] == '0') continue;
                stringstream ss; ss << s;
                ll n; ss >> n;
                if (isPrime(n)) {
                    cur += n;
                    DEBUG(n);
                }
            }
        }
        res += cur;
    }
    DEBUG(res);
    return 0;
}

