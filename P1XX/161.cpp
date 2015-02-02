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

long long p4[15];
long long f[14][10][262150];

int getBit(long long mask, int i) {
    return (mask % p4[i+1]) / p4[i];
}
int setBit(long long mask, int i, int val) {
    return mask + (val - getBit(mask, i)) * p4[i];
}

int main() {
    const int m = 12;
    const int n = 9;
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(n);
    p4[0] = 1LL; FOR(i,1,14) p4[i] = p4[i-1] * 4LL;
    memset(f, 0, sizeof f);
    f[1][1][p4[n]-1] = 1;
    FOR(i,1,m) FOR(j,1,n) {
        int ii = i, jj = j + 1;
        if (jj == n+1) {
            ++ii;
            jj = 1;
        }
        REP(mask,p4[n]) if (f[i][j][mask]) {
            long long cur = f[i][j][mask];
            int x = (j >= 3) ? getBit(mask, j-3) : 3;
            int y = (j >= 2) ? getBit(mask, j-2) : 3;
            int z = getBit(mask, j-1);
            int t = (j < n) ? getBit(mask, j) : 3;

            // |
            if (z == 0) {
                f[ii][jj][setBit(mask, j-1, 3)] += cur;
            }
            if (z >= 2) {
                int newZ = (z-2) * 2;
                // Add nothing
                f[ii][jj][setBit(mask, j-1, newZ)] += f[i][j][mask];

                newZ++;

                // ---
                if (x % 2 == 0 && y % 2 == 0) {
                    int newMask = setBit(mask, j-1, newZ);
                    newMask = setBit(newMask, j-2, y+1);
                    newMask = setBit(newMask, j-3, x+1);
                    f[ii][jj][newMask] += f[i][j][mask];
                }
                // --
                // |
                if (z % 2 == 0 && t % 2 == 0) {
                    int newMask = setBit(mask, j-1, 3);
                    newMask = setBit(newMask, j, t+1);
                    f[ii][jj][newMask] += f[i][j][mask];
                }
                // --
                //  |
                if (z % 2 == 0 && y < 2) {
                    int newMask = setBit(mask, j-1, 3);
                    newMask = setBit(newMask, j-2, y + 2);
                    f[ii][jj][newMask] += f[i][j][mask];
                }
                // |
                // --
                if (y == 0) {
                    int newMask = setBit(mask, j-1, newZ);
                    newMask = setBit(newMask, j-2, 3);
                    f[ii][jj][newMask] += f[i][j][mask];
                }
                //  |
                // --
                if (z % 2 == 0 && y % 2 == 0) {
                    int newMask = setBit(mask, j-1, 3);
                    newMask = setBit(newMask, j-2, y+1);
                    f[ii][jj][newMask] += f[i][j][mask];
                }
            }
        }
    }
    DEBUG(f[3][1][p4[n]-1]);
    DEBUG(f[m+1][1][p4[n]-1]);
    return 0;
}

