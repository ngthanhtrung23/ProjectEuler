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

const int MN = 9000111;
const int N = 500500;
int sieve[MN], primes[MN], nPrime;

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,2,4000) if (!sieve[i]) {
        int j = i*i;
        while (j < MN) {
            sieve[j] = i;
            j += i;
        }
    }
    FOR(i,2,MN-1) if (!sieve[i]) {
        primes[++nPrime] = i;
    }
    DEBUG(nPrime);

    set< pair<long long, int> > s;
    FOR(i,1,N) s.insert(make_pair(primes[i], primes[i]));
    
    long long res = 1;
    REP(turn,N) {
        auto cur = s.begin();
        long long prod = cur->first;
        int p = cur->second;

        res = (res * prod) % 500500507;

        s.erase(s.begin());
        s.insert(make_pair(prod * prod, p));
    }
    DEBUG(res);


    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

