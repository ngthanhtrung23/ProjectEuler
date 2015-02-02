#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (long long)(x))
using namespace std;

const int MN = 1000111;
int cache[MN];
bool isSquare(long long x) {
    if (x < MN && cache[x] >= 0) return cache[x]; 
    long long t = round(sqrt(x)) - 2;
    while (t*t < x) ++t;
    if (x < MN)
        return cache[x] = t*t == x;
    else return t*t == x;
}

int get(int m) {
    int res = 0;
    FOR(a,1,m) FOR(b,a,m) FOR(c,b,m) {
        long long nn = sqr(c) + sqr(a+b);
        if (isSquare(nn)) ++res;
    }
    return res;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    memset(cache, -1, sizeof cache);
    int l = 1000, r = 2000, res = 2000;
    while (l <= r) {
        cout << l << ' ' << r << "  --> " << res << endl;
        int mid = (l + r) >> 1;
        if (get(mid) >= 1000000) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res << endl;
    return 0;
}

