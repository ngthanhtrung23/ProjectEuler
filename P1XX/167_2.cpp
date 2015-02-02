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

const int MAX = 10111;

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
    while (x + cycle[k] < saveN[k]) x += saveN[k];
    if (debug) DEBUG(x);

    if (debug) DEBUG(saveN[k]);

    return u[k][x] + cycleSum[k] * ((n - x) / cycle[k]);
}

const int oo = 10111000;
int cnt[oo];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(n,2,10) {
        a[1] = 2, a[2] = 2*n+1;
        memset(cnt, 0, sizeof cnt);

        cnt[a[1] + a[2]] = 1;
        int N = MAX;
        if (n > 7) N *= 7;

        int cntEven = 0;
        vector<int> evens;
        evens.push_back(a[1]);

        FOR(i,3,N) {
            if (i % 10000 == 0) cout << '.' << endl;
            a[i] = a[i-1] + 1;
            while (a[i] < oo && cnt[a[i]] != 1) {
                ++a[i];
            }
            assert(a[i] < oo);

            if (a[i] % 2 == 0) evens.push_back(a[i]);

            FOR(j,1,i-1) {
                cnt[a[i] + a[j]] += 1;
            }
        }
        cout << "---------------------------------------------------" << endl;
        DEBUG(n);
        DEBUG(N);
        DEBUG(a[N]);
        DEBUG(evens.size());
        assert(evens.size() == 2);
    }


    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

// res = 
