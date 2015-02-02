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

long long c2(long long n) {
    return n * (n-1) / 2LL;
}

int a[200][200], sum[200][200];

int get(int i1, int j1, int i2, int j2) {
    return sum[i2][j2] - sum[i2][j1-1] - sum[i1-1][j2] + sum[i1-1][j1-1];
}

long long get(int row, int col) {
    int m, n;

    long long res = 0;
    res += c2(row+1) * c2(col+1);

    int i = 0;
    int from = col + 5, to = from - 1;
    FOR(turn,1,row-1) {
        --from; ++to;
        ++i;
        FOR(j,from,to) a[i][j] = 1;
    }
    int x = row-1;
    --from;
    while (x+1 < col) {
        ++from; ++to;
        ++i;
        FOR(j,from,to) a[i][j] = 1;
        ++x;
    }
    ++to;
    n = to;
    FOR(turn,1,row-1) {
        ++from; --to;
        ++i;
        FOR(j,from,to) a[i][j] = 1;
    }
    m = i;

    FOR(i,1,m) FOR(j,1,n) {
        sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (1 - a[i][j]);
    }

    FOR(i1,1,m) FOR(i2,i1,m)
        FOR(j1,1,n) FOR(j2,j1,n) {
            if (get(i1, j1, i2, j2) == 0) ++res;
            else break;
        }

    FOR(i,1,m) FOR(j,1,n) a[i][j] = 0;

    return res;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    long long res = 0;
    FOR(row,1,43) FOR(col,1,47) {
        if (row < col) res += get(row, col);
        else res += get(col, row);
    }

    DEBUG(res);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

