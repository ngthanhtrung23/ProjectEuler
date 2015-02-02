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

const int p = 1009;
const int q = 3643;
const long long n  = p*q;
const long long phi = (p-1) * (q-1);

long long powMod(long long x, long long k) {
    if (k == 0) return 1 % n;
    if (k == 1) return x % n;

    long long mid = powMod(x*x % n, k >> 1);
    if (k & 1) return mid * x % n;
    else return mid;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    int turn = 0, nn = 1000111000, all = 0;
    long long res = 0;
    set<int> allm;
    FOR(e,2,phi-1) if (__gcd(e, (int) phi) == 1) {
        if (__gcd(e, p-1) == 1 && __gcd(e, q-1) == 1) {
            int cnt = 0;
            for(auto m : allm) {
                if (powMod(m, e) == m) {
                    ++cnt;
                    if (cnt > 7) break;
                }
            }
            if (cnt <= 7) {
                FOR(m,2,n-1) if (!allm.count(m)) {
                    if (powMod(m, e) == m) {
                        allm.insert(m);
                        ++cnt;
                        if (cnt > 7) break;
                    }
                }
            }
            if (cnt < nn) {
                nn = cnt;
                res = e;
                all = 1;
            }
            else if (cnt == nn) {
                res += e;
                all++;
            }
            if (nn == cnt && all % 10 == 0) {
                cout << e << ' ' << cnt << " --> " << nn << ' ' << all << ' ' << res << endl;
//                assert(__gcd(e, p-1) == 1);
//                assert(__gcd(e, q-1) == 1);
                cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
            }
        }
    }
    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

