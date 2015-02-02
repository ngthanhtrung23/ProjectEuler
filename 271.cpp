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

long long mul(long long a, long long b, long long mod) {
    if (b == 0) return 0;
    if (b == 1) return a % mod;
    if (a <= 1000111000111000111LL / b) return (a * b) % mod;

    long long mid = mul((a + a) % mod, b >> 1, mod);
    if (b & 1) return (mid + a) % mod;
    else return mid;
}

vector<long long> generate(vector<long long> cur, long long cur_mod, long long p) {
    long long next_mod = cur_mod * p;
    vector<long long> res;
    for(long long i : cur) {
        for(long long x = i; x < next_mod; x += cur_mod) {
            long long cube = mul(x, mul(x, x, next_mod), next_mod);
            assert(cube > 0);
            if (cube == 1) {
                res.push_back(x);
            }
        }
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    return res;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    vector<long long> primes = {13};
    vector<long long> res = {1, 2, 4};
    long long cur_mod = 7;

    primes = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
    res = {1};
    cur_mod = 2;

    for(auto p : primes) {
        res = generate(res, cur_mod, p);
        cur_mod *= p;
//        PR0(res, res.size());
        DEBUG(cur_mod);
    }

    long long sum = 0;
    for(auto x : res)
        if (x > 1) sum += x;
    DEBUG(sum);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

