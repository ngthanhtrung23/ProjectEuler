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

long long t = 0, s[500511], a[1011][1011], row[1011][1011];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    t = 0;
    FOR(k,1,500500) {
        t = (615949*t + 797807) % (1<<20);
        s[k] = t - (1<<19);
    }
    PR(s, 3);
    int k = 0;
    FOR(i,1,1000) FOR(j,1,i) {
        a[i][j] = s[++k];
        row[i][j] = row[i][j-1] + a[i][j];
    }
    PR(a[1], 1);
    PR(a[2], 2);

    long long res = 0;
    FOR(i,1,1000) FOR(j,1,i) {
        long long sum = 0;
        for(int bottom = i, sz = 1; bottom <= 1000; bottom++, sz++) {
            sum += row[bottom][j+sz-1] - row[bottom][j-1];
            res = min(res, sum);
        }
    }
    DEBUG(res);
    return 0;
}

