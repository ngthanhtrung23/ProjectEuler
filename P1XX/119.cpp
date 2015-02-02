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

int get(long long x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    int cnt = 0;
    FOR(ndigit,2,20) {
        vector<long long> res;

        long long bound = 1;
        FOR(i,1,ndigit) bound = bound * 10LL;

        FOR(dig_sum,ndigit*1 + 1,ndigit*9) {
            for(long long num = dig_sum; num < bound; num *= dig_sum) if (num >= bound / 10) {
                if (get(num) == dig_sum) res.push_back(num);
            }
        }

        sort(res.begin(), res.end());
        for(auto x : res) {
            ++cnt;
            cout << cnt << ": " << x << endl;
        }
        if (cnt >= 30) break;
    }

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

