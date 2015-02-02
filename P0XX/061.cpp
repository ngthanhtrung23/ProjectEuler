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

vector<int> x[6];
bool mark[6][10111];
int num(int t, int n) {
    switch (t) {
        case 0: return n * (n+1) / 2;
        case 1: return n * n;
        case 2: return n * (3*n-1) / 2;
        case 3: return n * (2*n-1);
        case 4: return n * (5*n-3) / 2;
        case 5: return n * (3*n-2);
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    REP(t,6) {
        int n = 1;
        while (num(t, n) <= 9999) {
            int cur = num(t, n);
            if (cur >= 1000) {
                x[t].push_back(cur);
                mark[t][cur] = true;
            }
            ++n;
        }
        DEBUG(x[t].size());
    }
    int typ[10];
    REP(t,6) typ[t] = t;
    do {
        FOR(a,10,99)
            FOR(b,10,99)
            if (mark[typ[0]][a*100+b])
                FOR(c,10,99)
                if (mark[typ[1]][b*100+c])
                    FOR(d,10,99)
                    if (mark[typ[2]][c*100+d])
                        FOR(e,10,99)
                        if (mark[typ[3]][d*100+e])
                            FOR(f,10,99)
                            if (mark[typ[4]][e*100+f] && mark[typ[5]][f*100+a]) {
                                cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << endl;
                                cout << (a*100+b) + (b*100+c) + (c*100 + d) + (d*100 + e) + (e*100 + f) + (f*100 + a) << endl;
                            }
    } while (next_permutation(typ, typ+6));
    return 0;
}

