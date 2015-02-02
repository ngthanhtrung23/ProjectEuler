#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ','; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
using namespace std;

const int MAX = 1000111;

int a[MAX*111 + 10];
long long cycle[11];
vector<long long> u[11];
long long cycleSum[11], saveN[11];

long long get(int k, long long n, bool debug = false) {
    if (n <= saveN[k]) return u[k][n];

    long long x = n % cycle[k] + (saveN[k] / cycle[k]) * cycle[k];
    if (debug) DEBUG(x);
    while (x >= saveN[k]) x -= cycle[k];
    if (debug) DEBUG(x);
    while (x + cycle[k] < saveN[k]) x += cycle[k];
    if (debug) DEBUG(x);

    if (debug) DEBUG(saveN[k]);

    return u[k][x] + cycleSum[k] * ((n - x) / cycle[k]);
}

int cnt[1000111];
int ulam[1000111];
void verify_numbers() {
    FOR(n,2,10) {
        DEBUG(n);
        memset(cnt, 0, sizeof cnt);
        ulam[1] = 2; ulam[2] = 2*n+1;
        cnt[ulam[1] + ulam[2]] = 1;

        assert(ulam[1] == u[n][1]);
        assert(ulam[2] == u[n][2]);

        FOR(i,3,10000) {
            ulam[i] = ulam[i-1] + 1;
            while (cnt[ulam[i]] != 1) ++ulam[i];
            if (u[n][i] != ulam[i]) {
                DEBUG(i);
                DEBUG(ulam[i]);
                DEBUG(u[n][i]);
                assert(ulam[i] == u[n][i]);
            }

            FOR(j,1,i-1)
                ++cnt[ulam[j] + ulam[i]];
        }
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(n,2,10) {
        a[1] = 2, a[2] = 2*n+1;

        unordered_map<int,int> cnt;
        cnt[a[1] + a[2]] = 1;
        int N = MAX;
        if (n > 7) N *= 10;
        if (n == 10) N = MAX * 30;

        int cntEven = 0;
        vector<int> evens;
        evens.push_back(a[1]);

        FOR(i,3,N) {
            if (i % 1000000 == 0) cout << '.' << endl;
            a[i] = a[i-1] + 1;
            while (a[i] % 2 == 0 && evens.size() == 2) ++a[i];
            while (!cnt.count(a[i]) || cnt[a[i]] != 1) {
                ++a[i];
                if (evens.size() == 2) ++a[i];
            }

            if (evens.size() < 2) {
                FOR(j,1,i-1) {
                    cnt[a[i] + a[j]] += 1;
                }
            }
            else {
                cnt[a[i] + evens[0]] += 1;
                cnt[a[i] + evens[1]] += 1;
            }
            if (a[i] % 2 == 0) evens.push_back(a[i]);
        }
        assert(a[1] == 2);
        assert(a[2] == 2*n+1);
        assert(a[3] == a[1] + a[2]);
        cout << "---------------------------------------------------" << endl;
        DEBUG(n);
        DEBUG(N);
        DEBUG(a[N]);
        int tmp[] = {0, 0, 32, 26, 444, 1628, 5906, 80, 126960, 380882, 2097152};
        int lb[]  = {0, 0, 100111, 100111, 100111, 100111, 100111, 100111, 1000111, 1000111, 3111000};
        FOR(cycleLen,10,tmp[n]) {
            bool ok = true;
            FOR(i,lb[n],N)
                if (a[i]-a[i-1] != a[i - cycleLen] - a[i - cycleLen - 1]) {
                    ok = false;
                    break;
                }
            if (ok) {
                DEBUG(cycleLen);
                cycle[n] = cycleLen;
                break;
            }
        }

        u[n].push_back(0);
        FOR(i,1,N) u[n].push_back(a[i]);
        saveN[n] = lb[n];

        // a[i] - a[i-1] == a[i-cycleLen] - a[i-cycleLen-1]
        cycleSum[n] = a[N] - a[N-cycle[n]];
    }
    verify_numbers();

    FOR(i,2,10) {
        DEBUG(i);
        DEBUG(cycle[i]);
        assert(u[i][1] == 2);
        assert(u[i][2] == 2*i+1);
        FOR(j,1,saveN[i]*9)
            if (u[i][j] != get(i, j)) {
                DEBUG(u[i][j]);
                DEBUG(get(i, j));
                get(i, j, true);
                return 0;
            }
        DEBUG("OK");
    }

    long long res = 0;
    FOR(i,2,10) {
        res += get(i, 1000LL * 1000LL * 1000LL * 100);
        DEBUG(res);
    }
    DEBUG(res);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

