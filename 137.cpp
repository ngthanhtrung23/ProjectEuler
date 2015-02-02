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

bool isSquare(long long x, long long& t) {
    t = sqrt(x) - 5;
    while (t*t < x) ++t;
    return t*t == x;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    int cnt = 0;
    for(long long k = 0; k <= 1111000111000LL; ++k) {
        long long d = sqr(k+1LL) + 4LL*k*k;
        assert(d > 0);
        long long x;
        if (isSquare(d, x)) {
            ++cnt;
            DEBUG(cnt);
            DEBUG(k);
            DEBUG(d);

            long long tu = -(k+1) + x;
            long long mau = 2*k;

            long long g = __gcd(tu, mau);
            tu /= g;
            mau /= g;
            cout << tu << '/' << mau << endl;
            if (cnt == 15) break;
        }
    }

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

