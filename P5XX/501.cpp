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
int sieve[MN], pi[MN];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,2,1000) if (!sieve[i]) {
        for(int j = i*i; j < MN; j += i) {
            sieve[j] = i;
        }
    }

    long long sum = 0;
    FOR(i,2,MN-1) {
        pi[i] = pi[i-1];
        if (!sieve[i]) ++pi[i];
    }

    long long INF = 1000 * 1000;

    int res = 0;
    for(long long i = 2; i*i*i * i*i*i*i <= INF; ++i)
        if (!sieve[i])
            ++res;

    for(long long i = 2; i*i*i <= INF; ++i) if (!sieve[i]) {
        long long bound = INF / i / i / i;
        res += pi[bound];
        if (bound >= i) --res;
    }

    for(long long i = 2; i <= 1000; ++i)
        if (!sieve[i]) {
            long long bound = min(i - 1, INF / i / i);
            for(int j = 2; j <= bound; ++j)
                if (!sieve[j]) {
                    long long bound = INF / i / j;
                    if (bound >= i)
                        res += pi[bound] - pi[i];
                }
        }

    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

