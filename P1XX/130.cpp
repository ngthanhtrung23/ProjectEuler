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
int sieve[MN + 5], phi[MN + 5];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,2,1000) if (!sieve[i]) {
        for(int j = i*i; j <= MN; j += i) {
            sieve[j] = i;
        }
    }

    FOR(i,2,MN) {
        if (!sieve[i]) phi[i] = i-1;
        else {
            int u = i, p = sieve[i];
            while (u % p == 0) {
                u /= p;
            }
            if (u == 1) phi[i] = i - i / p;
            else phi[i] = phi[u] * phi[i/u];
        }
    }

    int sum = 0, cnt = 0;
    FOR(i,2,MN) if (sieve[i]) {
        int rem = 0;
        FOR(l,1,phi[i]) {
            rem = (rem * 10 + 1) % i;
            if (rem == 0) {
                if ((i-1) % l == 0) {
                    ++cnt;
                    sum += i;
                    cout << cnt << ": " << i << ' ' << sum << endl;
                    if (cnt == 25) goto done;
                }
                break;
            }
        }
    }

done:
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

