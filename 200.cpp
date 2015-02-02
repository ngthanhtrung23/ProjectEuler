#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define cube(x) ((x) * (x) * (x))
using namespace std;

const int MN = 1000111;
int sieve[MN];
long long primes[MN], nPrime;
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
// {2,7,61,-1}                      is for n < 4759123141 (= 2^32)
// {2,3,5,7,11,13,17,19,23,-1} is for n < 10^15 (at least)
bool isPrime(ll n) {
    if (n <= 1 || (n > 2 && n % 2 == 0)) return false;
    ll test[] = {2,3,5,7,11,13,17,19,23,-1};
    ll d = n - 1, s = 0;
    while (d % 2 == 0) ++s, d /= 2;
    for (int i = 0; test[i] < n && test[i] != -1; ++i)
        if (!suspect(test[i], s, d, n)) return false;
    return true;
}

bool check(long long x) {
    stringstream ss; ss << x;
    string s = ss.str();
    if (s.find("200") == string::npos) return false;

    REP(i,s.size())
        FOR(to,'0','9')
        if (to != s[i]) {
            char old = s[i];
            s[i] = to;
            stringstream ss2(s);
            long long t; ss2 >> t;
            if (isPrime(t)) return false;
            s[i] = old;
        }
    return true;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,2,4000) if (!sieve[i]) {
        for(int j = i*i; j < MN; j += i)
            sieve[j] = i;
    }
    FOR(i,2,MN-1) if (!sieve[i])
        primes[++nPrime] = i;

    set< pair<long long, pair<int,int> > > all;
    FOR(i,1,nPrime-1) all.insert(make_pair(sqr(primes[i]) * cube(primes[1]), make_pair(i, 1)));

    int cnt = 0;
    while (true) {
        auto cur = *all.begin();
        all.erase(all.begin());

        int i = cur.second.first, j = cur.second.second;
        if (j < nPrime)
            all.insert(make_pair(sqr(primes[i]) * cube(primes[j+1]), make_pair(i, j+1)));
        long long x = cur.first;
        if (i != j && check(x)) {
            ++cnt;
            cout << x << ' ' << primes[i] << ' ' << primes[j] << endl;
            if (cnt == 200) {
                DEBUG(x);
                break;
            }
        }
    }

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

