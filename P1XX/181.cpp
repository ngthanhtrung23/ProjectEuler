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

const int black = 60;
const int white = 40;

long long f[66][44][66][44];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(add_b,0,black) FOR(add_w,0,white)
        f[0][0][add_b][add_w] = 1;

    FOR(b,0,black) FOR(w,0,white)
        if (b || w)
            FOR(add_b,0,black) FOR(add_w,0,white) {
                int prev_b = add_b, prev_w = add_w - 1;
                if (prev_w < 0) {
                    prev_b -= 1;
                    prev_w = white;
                }
                f[b][w][add_b][add_w] = f[b][w][prev_b][prev_w];
                if (add_b <= b && add_w <= w)
                    f[b][w][add_b][add_w] += f[b - add_b][w - add_w][add_b][add_w];
            }

    DEBUG(f[black][white][black][white]);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

