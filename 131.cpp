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

bool isCube(long long x) {
    long long t = pow(x, 1.0 / 3) - 5;
    while (t*t*t < x) ++t;
    return t*t*t == x;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,2,1000) if (!sieve[i]) {
        for(int j = i*i; j <= MN; j += i) {
            sieve[j] = i;
        }
    }

    int cnt = 0;
    for(long long x = 1; x <= 1000111; ++x)
        for(long long n = 1; n < x; ++n) {
            long long t = x*x*x - n*n*n;
            if (t % (n*n) == 0 && t/n/n < 1000 * 1000) {
                if (sieve[t/n/n] == 0) {
                    cnt ++;
                    cout << cnt << ": p = " << t/n/n << ", n = " << n << " (" << (fixed) << setprecision(2) << pow(n, 1.0/3) << "^3), x = " << x << endl;
                    break;
                }
            }
        }

    DEBUG(cnt);
    
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

