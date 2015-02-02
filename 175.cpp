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

long long f[1000111][22], a[1000111];

long long get(long long x, long long y) {
    long long g = __gcd(x, y);
    x /= g; y /= g;

    vector< pair<long long, long long> > path;

    long long nstep = 0;
    while (x > 1 || y > 1) {
        path.push_back(make_pair(x, y));
        
        if (x <= y) y -= x;
        else x -= y;
        ++nstep;

        if (nstep % 100111000 == 0) {
            cout << nstep << ' ' << x << ' ' << y << endl;
        }
    }
    reverse(path.begin(), path.end());

    x = 1, y = 1;

    vector< pair<int,int> > res;
    res.push_back(make_pair(1, 1));
    for(auto p : path) {
        int cur;
        if (p == make_pair(x, x + y)) {
            cur = 0;
        }
        else {
            cur = 1;
        }

        if (cur == res.back().first) ++res.back().second;
        else res.push_back(make_pair(cur, 1));

        x = p.first; y = p.second;
    }
    for(auto p : res) cout << p.second << ',';
    return 0;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    memset(f, 0, sizeof f);
    FOR(t,0,20) f[0][t] = 1;
    FOR(i,1,1000110) FOR(t,1,21) {
        f[i][t] = f[i][t-1];
        if (i >= (1<<(t-1))) f[i][t] += f[i - (1<<(t-1))][t-1];
        if (i >= (1<<t)) f[i][t] += f[i - (1<<t)][t-1];
    }
//    FOR(i,1,100) if (i % 2 == 1) cout << f[i][20] << ' '; cout << endl;

    a[1] = 1; a[2] = 1;
    FOR(i,3,1000000) a[i] = f[i-1][20];

    FOR(i,3,1000000) {
        if (i % 2 == 0) assert(a[i] == a[i/2]);
        else assert(a[i] == a[i/2] + a[i/2+1]);
    }

    // http://en.wikipedia.org/wiki/Calkin%E2%80%93Wilf_tree

//    FOR(i,2,999999) {
//        if (i % 100000 == 0) DEBUG(i);
//        long long x = get(a[i], a[i+1]);
//        assert(x == i);
//    }
//    long long n = get(17, 13);
    long long n = get(987654321, 123456789);
    cout << endl;

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

