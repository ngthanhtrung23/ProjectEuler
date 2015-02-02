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

int p3[15];

int getBit(int mask, int i) {
    return (mask % p3[i+1]) / p3[i];
}

int setBit(int mask, int i, int val) {
    return mask + p3[i] * (val - getBit(mask, i));
}

const int m = 32;
const int n = 10;
long long f[m + 1][n+1][60111];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    p3[0] = 1; FOR(i,1,14) p3[i] = p3[i-1] * 3LL;
    assert(p3[n] < 60111);

    f[0][0][p3[n]-1] = 1;
    REP(i,m) REP(j,n) {
        int ii = i, jj = j + 1;
        if (jj == n) jj = 0, ii++;

        REP(mask,p3[n]) if (f[i][j][mask]) {
            int x = getBit(mask, j);
            // Do not put anything
            if (x) {
                f[ii][jj][setBit(mask, j, x - 1)] += f[i][j][mask];
            }
            // Put 1*2
            if (x == 1) {
                if (i == m-1 || j == 0 || getBit(mask, j-1) != 2) {
                    f[ii][jj][setBit(mask, j, 2)] += f[i][j][mask];
                }
            }
            // Put 1*3
            if (x == 0) {
                if (i == m-1 || j == 0 || getBit(mask, j-1) != 2) {
                    f[ii][jj][setBit(mask, j, 2)] += f[i][j][mask];
                }
            }
        }
    }
    DEBUG(f[m][0][p3[n]-1]);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

