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

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    // a1 < ... < a7
    // a7 < a1 + a2 < ... < a6 + a7
    // a6 + a7 < a1 + a2 + a3 < ... < a5 + a6 + a7
    // a5 + a6 + a7 < a1 + a2 + a3 + a4 < ... < a4 + a5 + a6 + a7
    // a4 + a5 + a6 + a7 < a1 + a2 + a3 + a4 + a5 < ... < a3 + a4 + a5 + a6 + a7
    // a3 + a4 + a5 + a6 + a7 < a1 + a2 + a3 + a4 + a5 + a6 < ... < a2 + a3 + a4 + a5 + a6 + a7

    // a1
    // a7 > ... > a1
    // a2 > a7 - a1
    // a6 > a2
    // a3 > a6 + a7 - a1 - a2
    // a5 > a3
    // a4 > a3
    // a4 > a5 + a6 + a7 - a1 - a2 - a3

    // 20, 31, 38, 39, 40, 42, 45
    int best = 255;
    int save[] = {20, 31, 38, 39, 40, 42, 45};
    FOR(a1,15,30) {
        FOR(a7,a1+6,best-6*a1-15)
            FOR(a2,a1+1,best-6*a1-20)
            if (a1 + a2 > a7)
                FOR(a6,a2+4, best-a2-a7-5*a1-14)
                    FOR(a3,a2+1,best-6*a1-19)
                    if (a1 + a2 + a3 > a6 + a7)
                        FOR(a5,a3+2,a6-1)
                            FOR(a4,a3+1,a5-1)
                            if (a1 < a2 && a2 < a3 && a3 < a4 && a4 < a5 && a5 < a6 && a6 < a7)
                                if (a1 + a2 + a3 > a6 + a7)
                                    if (a1 + a2 + a3 + a4 > a5 + a6 + a7)
                                    if (a1 + a2 + a3 + a4 + a5 + a6 + a7 < best) {
                                        int cur[] = {a1,a2,a3,a4,a5,a6,a7};
                                        set<int> s;
                                        bool ok = true;
                                        REP(mask,128) {
                                            int sum = 0;
                                            REP(i,7) if ((mask>>i) & 1) sum += cur[i];
                                            if (s.count(sum)) {
                                                ok = false;
                                                break;
                                            }
                                            s.insert(sum);
                                        }
                                        if (ok) {
                                            best = a1 + a2 + a3 + a4 + a5 + a6 + a7;
                                            DEBUG(best);
                                            REP(i,7) save[i] = cur[i];
                                        }
                                    }
    }

    DEBUG(best);
    PR0(save, 7);
    return 0;
}

