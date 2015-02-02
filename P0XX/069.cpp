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

const int MN = 1000 * 1000;
long long phi[MN + 5];
int sieve[MN + 5];

void init() {
    for(int i = 2; i * i <= MN; ++i) if (!sieve[i]) {
        int j = i*i;
        while (j <= MN) {
            sieve[j] = i;
            j += i;
        }
    }
    int best = 2;
    FOR(i,2,MN) {
        if (!sieve[i]) phi[i] = i-1;
        else {
            int p = sieve[i];
            int u = i;
            while (u % p == 0) u /= p;

            if (u == 1) phi[i] = (i/p) * (p-1);
            else phi[i] = phi[u] * phi[i/u];
        }

        if (i <= 10) {
            cout << i << ' ' << phi[i] << endl;
        }
        if (i * phi[best] > best * phi[i]) best = i;
    }
    DEBUG(best);
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    init();
    return 0;
}

