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

const int MAX = 1<<25;
long long oo = (1LL) << 50;

int sieve[MAX], hasSquare[MAX], cnt[MAX], np[MAX];

long long get(long long x) {
    x = x * x;
    if (oo % x == 0) return oo / x - 1;
    else return oo / x;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,2,1<<13) if (!sieve[i]) {
        int j = i*i;
        while (j < MAX) {
            sieve[j] = i;
            j += i;
        }
    }
    DEBUG(sieve[4]);
    FOR(i,2,MAX-1) {
        if (!sieve[i]) {
            np[i] = 1;
            continue;
        }

        int p = sieve[i];
        int u = i / p;
        if (u % p == 0) hasSquare[i] = true;
        else hasSquare[i] = hasSquare[u];

        np[i] = np[u] + 1;
    }
    DEBUG(np[30]);

    sieve[1] = 1;
    FOR(i,1,MAX-1) {
        cnt[i] = cnt[i-1];
        if (!hasSquare[i]) ++cnt[i];
    }
    assert(cnt[32] == 20);

    long long res = 0;

    FOR(i,1,MAX-1) if (!hasSquare[i]) {
        long long cur = get(i);
        if (np[i] % 2 == 1) res -= cur;
        else res += cur;
    }
    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

