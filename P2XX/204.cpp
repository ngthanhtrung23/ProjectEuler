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

bool isPrime(int n) {
    for(int i = 2; i*i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

#define TWO(X) (1<<(X))
#define CONTAIN(S,X) (S & TWO(X))

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    int oo = 1000 * 1000 * 1000;

    vector<int> primes;
    FOR(i,2,100) if (isPrime(i)) {
        primes.push_back(i);
    }
    cout << "DONE PRIME" << endl;

    queue<int> qu;
    unordered_set<int> s;
    qu.push(1);
    s.insert(1);
    while (!qu.empty()) {
        long long u = qu.front(); qu.pop();
        for(auto p : primes) {
            long long v = u * p;
            assert(v > 0);
            if (v > oo) break;
            if (v <= oo && s.find(v) == s.end()) {
                s.insert(v);
                qu.push(v);
            }
        }
    }
    DEBUG(s.size());

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

