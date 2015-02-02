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

bool bad(long long x, long long& t) {
    t = (long long) sqrt(x) - 2;
    while (t*t < x) ++t;
    return t*t != x;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    long long sum = 0;
    int cnt = 0;
    FOR(N,1,1000111000) for(int sign = -1; sign <= 1; sign += 2) {
        long long n = N;
        long long delta = 5*n*n + sign;
        long long t;
        if (bad(delta, t)) continue;

        REP(turn,2) {
            long long m;
            if (turn == 0) {
                m = 2*n + t;
            }
            else {
                m = 2*n - t;
            }
            if (m <= n) continue;
            if (__gcd(m, n) == 1 && (m - n) % 2 == 1) {
                if (abs(m*m - n*n - 4*m*n) == 1) {
                    cout << m*m + n*n << endl;
                    sum += m*m + n*n;
                    ++cnt;
                    if (cnt == 12) {
                        DEBUG(sum);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

