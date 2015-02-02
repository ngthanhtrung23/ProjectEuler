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

const int n = 20;
const int each = 12;
const int k = 10;
const int sum = 70;

long long gt[22], c[22][22];
long long f[22][22][1011];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    gt[0] = 1; FOR(i,1,20) gt[i] = gt[i-1] * i;
    FOR(i,0,20) {
        c[i][0] = 1;
        FOR(j,1,i) c[i][j] = c[i-1][j-1] + c[i-1][j];
    }

    // f[least][num][sum]
    memset(f, 0, sizeof f);
    FOR(least,1,each+2) {
        f[least][0][0] = 1;
        FOR(i,0,n-1) FOR(sum,0,1000)
            if (f[least][i][sum]) {
                FOR(add,least,each)
                    f[least][i+1][sum+add] += f[least][i][sum];
            }
    }
    cout << "DONE INIT" << endl;

    long long res = 0;
    FOR(greater,0,k-1) FOR(equal,1,n-greater) FOR(val,1,each)
    if (greater + equal >= k && greater + equal <= n && sum >= (k - greater) * val) {
        long long cur = 1;
        // Place greater
        cur = cur * c[n][greater] * f[val + 1][greater][sum - (k - greater) * val];

        // Place equal
        cur = cur * c[n - greater][equal];
        
        // Place smaller
        FOR(i,1,n-greater-equal)
            cur = cur * (val - 1);

        res += cur;
    }
    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

