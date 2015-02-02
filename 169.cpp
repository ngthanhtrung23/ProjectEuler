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

long long f[111][2];
long long bit[111];

void update(long long& x, long long val) {
    x += val;
    if (x < 0) DEBUG(x);
}

long long get(long long x) {
    memset(bit, 0, sizeof bit);
    int nbit = 25;
    DEBUG(x);
    while (x) {
        bit[++nbit] = x % 2;
        x /= 2;
    }
    PR(bit, nbit);
    memset(f, 0, sizeof f);
    f[0][0] = 1;

    FOR(i,0,nbit-1) {
        // rem == 0
        if (bit[i+1] == 1) {
            // add 2^i
            update(f[i+1][0], f[i][0]);
        }
        else {
            // add 0
            update(f[i+1][0], f[i][0]);
            // add 2^i + 2^i
            update(f[i+1][1], f[i][0]);
        }

        // rem == 1
        if (bit[i+1] == 1) {
            // add 0
            update(f[i+1][0], f[i][1]);
            // add 2^i + 2^i
            update(f[i+1][1], f[i][1]);
        }
        else {
            update(f[i+1][1], f[i][1]);
        }
    }

    return f[nbit][0];
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    long long x = 1; FOR(t,1,25) x *= 5LL;
    DEBUG(get(x));
    return 0;
}

