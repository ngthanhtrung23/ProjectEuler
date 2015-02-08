#include "template.h"
#include "library/modulo.h"
#include "library/matrix.h"

const ll MOD = (1e9) + 7;
Modulo<MOD> f[2][10111][2], higher[2][10111][2], lower[2][10111][2];

Modulo<MOD> get(int w, int h) {
    memset(f, 0, sizeof f);
    memset(higher, 0, sizeof higher);
    memset(lower, 0, sizeof lower);

    FOR(j,1,h) f[1][j][j % 2] = 1;

    FOR(col,1,w-1) {
        int cur = col % 2;
        // Accumulate values
        FORD(j,h,1) REP(t,2) higher[cur][j][t] = higher[cur][j+1][t] + f[cur][j][t];
        FOR(j,1,h) REP(t,2) lower[cur][j][t] = (j >= 2 ? lower[cur][j-2][t] : 0) + f[cur][j][t];

        // Calculate next column
        memset(f[1-cur], 0, sizeof f[1-cur]);
        FOR(j,1,h) REP(t,2) {
            f[1-cur][j][t] = higher[cur][j+1][t] + lower[cur][j][t] + lower[cur][j-1][1-t];
        }

    }

    Modulo<MOD> res = 0;
    FOR(j,1,h) res = res + f[w % 2][j][0];
    return res;
}

inline int encode(int j, int t, int h) {
    return h * t + j - 1;
}
Modulo<MOD> get2(ll w, int h) {
    Matrix< Modulo<MOD> > start(2*h, 1);
    FOR(j,1,h) start.values[ encode(j, j % 2, h) ][0] = 1;

    Matrix< Modulo<MOD> > trans(2*h, 2*h);
    REP(row,2*h) {
        int t = row / h, j = row % h + 1;

        FOR(jj,j+1,h) trans[row][encode(jj, t, h)] = 1;
        for(int jj = j; jj > 0; jj -= 2) trans[row][encode(jj, t, h)] = 1;
        for(int jj = j - 1; jj > 0; jj -= 2) trans[row][encode(jj, 1-t, h)] = 1;
    }

    trans = trans % (w - 1);
    start = trans * start;

    Modulo<MOD> res;
    REP(j,h)
        res = res + start[j][0];
    return res;
}

void solve() {
    DEBUG(MOD);

    assert(get(4, 2) - get(4, 1) == 10);
    assert(get(13, 10) - get(13, 9) == 3729050610636LL % MOD);
    assert(get(10, 13) - get(10, 12) == 37959702514LL % MOD);
    assert(get(100, 100) - get(100, 99) == 841913936);

    DEBUG(get2(4, 2) - get2(4, 1));
    assert(get2(4, 2) - get2(4, 1) == 10);

    DEBUG(get2(13, 10) - get2(13, 9));
    assert(get2(13, 10) - get2(13, 9) == 3729050610636LL % MOD);

    DEBUG(get2(10, 13) - get2(10, 12));

    assert(get2(10, 13) - get2(10, 12) == 37959702514LL % MOD);

//    DEBUG(get2(100, 100) - get2(100, 99));
//    assert(get2(100, 100) - get2(100, 99) == 841913936);

    cout << "DONE CHECK" << endl;

//    auto res1 = get2(1000000LL * 1000000, 100);
//    auto res2 = get(10000, 10000);
//
//    cout << res1 << ' ' << res2 << endl;

    FOR(w,1,10) {
        FOR(h,1,100) {
            cout << get(w, h) << ' ';
        }
        cout << endl;
    }
}

