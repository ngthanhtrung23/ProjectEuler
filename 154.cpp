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

const int MN = 200000;
int p2[MN + 5], p5[MN + 5];

int get(int n, int k) {
    if (n < k) return 0;
    return n/k + get(n/k, k);
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,1,MN) {
        p2[i] = get(i, 2);
        p5[i] = get(i, 5);
    }

    long long res = 0;
    FOR(a,0,MN) {
        if (p5[MN] - p5[a] >= 12 && p2[MN] - p2[a] >= 12)
            for(int b = 0, c = MN-a; b <= c; b++, c--)
                if (p5[MN] - p5[a] - p5[b] - p5[c] >= 12
                        && p2[MN] - p2[a] - p2[b] - p2[c] >= 12) {
                    ++res;
                    if (b < c) ++res;
                }
        if (a % 1000 == 0) DEBUG(a);
    }
    DEBUG(res);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

