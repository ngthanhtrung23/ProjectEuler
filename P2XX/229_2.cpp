#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
using namespace std;

const ll INF = 10 * 1000 * 1000;

bool isBad(int p) {
    if (p % 4 == 3) return true;
    if (p % 8 == 5 || p % 8 == 7) return true;
    if (p % 3 == 2) return true;
    if (p % 7 == 3 || p % 7 == 5 || p % 7 == 6) return true;
    return false;
}

int sieve[1000111];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    // Bad numbers:
    // = mod 4 = 2
    // = (bad prime)^(odd)

    FOR(i,2,2000) if (!sieve[i]) {
        for(int j = i*i; j < 1000111; j += i)
            sieve[j] = i;
    }

    set<int> all;
    for(int p = 2; p*p <= INF; ++p)
        if (!sieve[p] && isBad(p)) {
            if (p < 100) DEBUG(p);
            int pp = p*p;
            ll x = pp;
            while (x <= INF) {
                if ((x / pp) % p) all.insert(x);
                x += p*p;
            }
        }

    int res = 0;
    FOR(i,9,INF) {
        int u = i;
        if (u % 4 == 2) continue;

        while (u % 2 == 0) u /= 2;
        if (all.count(u)) continue;

        if (res < 10) DEBUG(i);
        ++res;
    }

    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

