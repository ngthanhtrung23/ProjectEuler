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

const int MN = 1000 * 10000;
long long phi[MN + 5];
int sieve[MN + 5];

int cnt[11];
bool isPerm(int a, int b) {
    memset(cnt, 0, sizeof cnt);
    while (a) {
        ++cnt[a%10];
        a /= 10;
    }
    while (b) {
        --cnt[b%10];
        b /= 10;
    }
    REP(i,10) if (cnt[i]) return false;
    return true;
}

void init() {
    for(int i = 2; i * i <= MN; ++i) if (!sieve[i]) {
        int j = i*i;
        while (j <= MN) {
            sieve[j] = i;
            j += i;
        }
    }
    int best = 87109;
    FOR(i,2,MN) {
        if (!sieve[i]) phi[i] = i-1;
        else {
            int p = sieve[i];
            int u = i;
            while (u % p == 0) u /= p;

            if (u == 1) phi[i] = (i/p) * (p-1);
            else phi[i] = phi[u] * phi[i/u];
        }

        if (isPerm(phi[i], i) && i * phi[best] < best * phi[i]) best = i;
    }
    DEBUG(best);
    DEBUG(phi[best]);
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    init();
    return 0;
}

