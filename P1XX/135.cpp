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

bool check(int u, int v) {
    if ((u + v) % 4) return false;
    if ((3*v - u) % 4 || 3*v <= u) return false;
    return true;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    // (x + 2d)^2 - (x + d)^2 - x^2 = n
    // 3d^2 + 2dx - x^2 = n
    // 3d^2 + 3dx - dx - x^2 = n
    // 3d(d + x) - x(d + x) = n
    // (3d - x) * (d + x) = n
    //
    // 3d - x = u
    // d + x = v
    //
    // d = (u + v) / 4
    // x = (3v - u) / 4

    int res = 0;
    FOR(i,1,999999) {
        int cnt = 0;
        for(int u = 1; u*u <= i; ++u) if (i % u == 0) {
            int v = i / u;
            if (check(u, v)) ++cnt;
            if (u != v && check(v, u)) ++cnt;
        }
        if (cnt == 10) {
            ++res;
            if (res == 1) {
                DEBUG(i);
            }
        }
    }
    DEBUG(res);
    return 0;
}

// 4989

