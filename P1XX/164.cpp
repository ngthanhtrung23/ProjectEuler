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

long long f[22][10][10][10];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(z,1,9)
        f[1][0][0][z] = 1;

    FOR(i,1,19) FOR(x,0,9) FOR(y,0,9) FOR(z,0,9)
        if (f[i][x][y][z])
            FOR(t,0,9)
                if (y + z + t <= 9) {
                    f[i+1][y][z][t] += f[i][x][y][z];
                    assert(f[i+1][y][z][t] >= 0);
                }

    long long res = 0;
    FOR(x,0,9) FOR(y,0,9) FOR(z,0,9) {
        res += f[20][x][y][z];
        assert(res >= 0);
    }
    DEBUG(res);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

