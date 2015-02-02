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

// f(days, cnt_one, a2, a3, a4, a5)
double f[17][17][2][4][8][16];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    f[1][0][1][1][1][1] = 1.0;
    FOR(days,1,15) FOR(cnt_one,0,days+1) REP(a2,2) REP(a3,4) REP(a4,8) REP(a5,16)
        if (f[days][cnt_one][a2][a3][a4][a5] > 1e-6) {
            int sum = a2 + a3 + a4 + a5;
            int days2 = days + 1;
            int cnt_one2 = cnt_one; if (sum == 1) cnt_one2++;
            int a2_2, a3_2, a4_2, a5_2;

            // pick a2
            if (a2) {
                a2_2 = a2 - 1;
                a3_2 = a3 + 1;
                a4_2 = a4 + 1;
                a5_2 = a5 + 1;
                f[days2][cnt_one2][a2_2][a3_2][a4_2][a5_2] += f[days][cnt_one][a2][a3][a4][a5] * a2 / (double) sum;
            }
            // pick a3
            if (a3) {
                a2_2 = a2;
                a3_2 = a3 - 1;
                a4_2 = a4 + 1;
                a5_2 = a5 + 1;
                f[days2][cnt_one2][a2_2][a3_2][a4_2][a5_2] += f[days][cnt_one][a2][a3][a4][a5] * a3 / (double) sum;
            }
            // pick a4
            if (a4) {
                a2_2 = a2;
                a3_2 = a3;
                a4_2 = a4 - 1;
                a5_2 = a5 + 1;
                f[days2][cnt_one2][a2_2][a3_2][a4_2][a5_2] += f[days][cnt_one][a2][a3][a4][a5] * a4 / (double) sum;
            }
            // pick a5
            if (a5) {
                a2_2 = a2;
                a3_2 = a3;
                a4_2 = a4;
                a5_2 = a5 - 1;
                f[days2][cnt_one2][a2_2][a3_2][a4_2][a5_2] += f[days][cnt_one][a2][a3][a4][a5] * a5 / (double) sum;
            }
        }

    double res = 0.0;
    FOR(cnt_one,1,14)
        res += cnt_one * f[16][cnt_one][0][0][0][0];
    DEBUG(res - 1);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

