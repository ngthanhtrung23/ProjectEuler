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

long long f[11][10111], g[11][10111];
int p3[11];

int getBit(int mask, int i) {
    return (mask % p3[i+1]) / p3[i];
}

int setBit(int mask, int i, int val) {
    return mask + p3[i] * (val - getBit(mask, i));
}

bool good1(int s1, int s2, int len) {
    REP(i,len)
        if (getBit(s1, i) == getBit(s2, i)) return false;
    return true;
}

bool good2(int s1, int s2, int len) {
    REP(i,len)
        if (getBit(s1, i) == getBit(s2, i)
                || getBit(s1, i) == getBit(s2, i+1))
            return false;
    return true;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    p3[0] = 1; FOR(i,1,10) p3[i] = p3[i-1] * 3;
    f[1][0] = f[1][1] = f[1][2] = 1;

    FOR(row,2,8) {
        DEBUG(row);

        REP(cur_mask,p3[row-1])
            REP(old_mask,p3[row-1])
                if (good1(old_mask, cur_mask, row-1))
                    g[row][cur_mask] += f[row-1][old_mask];

        REP(cur_mask,p3[row])
            REP(old_mask,p3[row-1])
                if (good2(old_mask, cur_mask, row-1))
                    f[row][cur_mask] += g[row][old_mask];
    }

    long long res = 0;
    REP(mask,p3[8])
        res += f[8][mask];
    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

