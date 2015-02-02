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

const long long SQRTN = 1LL << 23;

long long p[SQRTN], lookup = 0;
vector<bool> segmentSieve(long long L, long long H) {
    memset(p, 0, sizeof p);
    lookup = 0;
    if (!lookup) {
        for (long long i = 2; i < SQRTN; ++i) p[i] = i;
        for (long long i = 2; i*i < SQRTN; ++i)
            if (p[i])
            for (long long j = i*i; j < SQRTN; j += i)
                p[j] = 0;
        remove(p, p+SQRTN, 0);
        lookup = 1;
    }
    vector<bool> table(H - L);
    for (long long i = L; i < H; ++i) table[i - L] = 1;
    for (long long i = 0, j; p[i] * p[i] < H; ++i) { // O( \sqrt(H) )
        if (p[i] >= L) j = p[i] * p[i];
        else if (L % p[i] == 0) j = L;
        else j = L - (L % p[i]) + p[i];
        for (; j < H; j += p[i]) table[j-L] = 0;
    }
    return table;
}

long long up(long long n) {
    return n * (n + 1LL) / 2;
}

long long get(long long row) {
    vector<bool> a[5], good[5];
    REP(t,5) {
        int cur = row - 2 + t;
        long long from = up(cur - 1) + 1;
        long long to = up(cur);

        a[t] = segmentSieve(from, to);
        good[t].resize(a[t].size());
    }

    FOR(i,1,3) REP(j,a[i].size())
        if (a[i][j]) {
            int cnt = 0;
            FOR(di,-1,1) FOR(dj,-1,1)
                if (di || dj) {
                    int ii = i + di, jj = j + dj;
                    if (jj < a[ii].size() && a[ii][jj])
                        ++cnt;
                }

            if (cnt >= 2) {
                good[i][j] = true;
                FOR(di,-1,1) FOR(dj,-1,1)
                    if (di || dj) {
                        int ii = i + di, jj = j + dj;
                        if (jj < a[ii].size() && a[ii][jj])
                            good[ii][jj] = true;
                    }
            }
        }

    long long res = 0;
    REP(j,a[2].size()) {
        long long from = up(row - 1) + 1;
        long long to = up(row);
        if (good[2][j])
            res += from + j;
    }
    return res;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

//    DEBUG(get(8));
//    DEBUG(get(9));
    DEBUG(get(5678027) + get(7208785));

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

