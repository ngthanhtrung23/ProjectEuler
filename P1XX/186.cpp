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

const long long MOD = 1000000LL;

int s[22000111];
int lab[MOD + 5];

int getRoot(int u) {
    if (lab[u] < 0) return u;
    return lab[u] = getRoot(lab[u]);
}

void merge(int u, int v) {
    u = getRoot(u), v = getRoot(v);
    if (u == v) return ;
    int x = lab[u] + lab[v];
    if (lab[u] < lab[v]) {
        lab[v] = u;
        lab[u] = x;
    }
    else {
        lab[u] = v;
        lab[v] = x;
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,1,22000111) {
        if (i <= 55) {
            s[i] = (100003 - 200003LL * i + 300007LL * i % MOD * i % MOD * i) % MOD;
            if (s[i] < 0) s[i] += MOD;
        }
        else {
            s[i] = (s[i-24] + s[i-55]) % MOD;
        }
    }
    cout << "DONE GEN S" << endl;
    memset(lab, -1, sizeof lab);

    int cnt = 0;
    for(int i = 1; i <= 22000 * 1000; i += 2) {
        int from = s[i], to = s[i+1];
        if (from == to) continue;

        ++cnt;
        if (cnt % 100000 == 0) {
            DEBUG(cnt);
        }
        merge(from, to);

        int x = getRoot(524287);
        if (-lab[x] >= 990000) {
            DEBUG(cnt);
            break;
        }
    }

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

