#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
using namespace std;

const ll INF = 10 * 1000 * 1000;

int sieve[INF + 10];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,2,5000) if (!sieve[i]) {
        for(int j = i*i; j <= INF; j += i)
            sieve[j] = i;
    }

    int cnt = 0;
    set<int> squares;
    for(int i = 2; i*i <= INF; ++i)
        squares.insert(i*i);

    FOR(i,9,INF) {
        if (i % 1000000 == 0) DEBUG(i);
        if (i % 2 == 1 || i % 4 == 0) {
            int u = i;
            bool ok = true;
            while (u > 1) {
                int p = (sieve[u]) ? sieve[u] : u;
                int k = 0;
                while (u % p == 0) {
                    ++k;
                    u /= p;
                }
                if (p % 4 == 3 && k % 2 == 1) { ok = false; break; }
                if ((p % 8 == 5 || p % 8 == 7) && k % 2 == 1) { ok = false; break; }
                if (p % 3 == 2 && k % 2 == 1) { ok = false; break; }
                if (k % 2 == 1) if (p % 7 == 3 || p % 7 == 5 || p % 7 == 6) { ok = false; break; }
            }

            if (ok) {
                if (squares.count(i)) {
                    ok = false;
                    for(auto x : squares) {
                        if (x > i) break;
                        if (squares.count(i - x)) { ok = true; break; }
                    }
                    if (!ok) continue;

                    ok = false;
                    for(auto x : squares) {
                        if (x*2 > i) break;
                        if (squares.count(i - x - x)) { ok = true; break; }
                    }
                    if (!ok) continue;

                    ok = false;
                    for(auto x : squares) {
                        if (x*3 > i) break;
                        if (squares.count(i - 3*x)) { ok = true; break; }
                    }
                    if (!ok) continue;

                    ok = false;
                    for(auto x : squares) {
                        if (x*7 > i) break;
                        if (squares.count(i - 7*x)) { ok = true; break; }
                    }
                    if (!ok) continue;
                }
                ++cnt;
                if (cnt <= 20) DEBUG(i);
            }
        }
    }
    DEBUG(cnt);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

