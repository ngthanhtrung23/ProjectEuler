#include "template.h"

const int N = 30;

const int di[] = {-1,1,0,0};
const int dj[] = {0,0,-1,1};

double f[55][33][33];
double a[33][33][33][33];

void solve() {
    // Expected value(empty cells)
    // = sum( probability_is_empty(i, j) )

    // Find probability that cell(i, j) is empty
    // = product( (1 - probability that we go from (u, v) to (i, j)) )

    REP(starti,N) REP(startj,N) {
        memset(f, 0, sizeof f);
        f[0][starti][startj] = 1.0;
        REP(turn,50) {
            REP(i,N) REP(j,N) {
                int cnt = 0;
                REP(dir,4) {
                    int ii = i + di[dir], jj = j + dj[dir];
                    if (ii < 0 || ii >= 30 || jj < 0 || jj >= 30) continue;
                    ++cnt;
                }
                REP(dir,4) {
                    int ii = i + di[dir], jj = j + dj[dir];
                    if (ii < 0 || ii >= 30 || jj < 0 || jj >= 30) continue;

                    f[turn+1][ii][jj] += f[turn][i][j] / cnt;
                }
            }
        }

        REP(i,N) REP(j,N)
            a[starti][startj][i][j] = f[50][i][j];
    }
    cout << "DONE PART 1" << endl;

    double res = 0.0;
    REP(i,N) REP(j,N) {
        double prod = 1.0;
        REP(u,N) REP(v,N)
            prod *= 1.0 - a[u][v][i][j];
        res += prod;
    }
    DEBUG(res);
}

