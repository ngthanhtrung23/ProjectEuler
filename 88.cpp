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

int f[12111];

void go(int len, int cur, int prod, int sum) {
    if (len > 1) {
        int x = prod - sum + len;
        if (x <= 12000) f[x] = min(f[x], prod);
    }
    FOR(i,cur,12000) if (prod * i <= 24000) {
        go(len+1, i, prod * i, sum + i);
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    memset(f, 0x3f, sizeof f);
    go(0, 2, 1, 0);
    set<int> s;
    FOR(i,2,12000) s.insert(f[i]);
    DEBUG(f[2]);
    DEBUG(f[3]);
    DEBUG(f[4]);
    DEBUG(f[5]);
    DEBUG(f[6]);
    int res = 0;
    for(auto x : s) res += x;
    cout << res << endl;
    return 0;
}

