#include "template.h"
#include "library/RabinMiller.h"

const ll INF = 1000000LL * 1000000 * 10000;
void solve() {
    DEBUG(INF);
    vector<int> primes;
    FOR(i,2,100) if (isPrime(i)) primes.push_back(i);
    DEBUG(primes.size());

    ll all = INF;
    
    REP(mask,TWO(25)) {
        ll prod = 1;
        REP(i,25) if (CONTAIN(mask,i)) prod *= primes[i];

        if (__builtin_popcount(mask) & 1) all += INF / prod;
        else all -= INF / prod;
    }
    cout << "DONE 0" << endl;
    REP(ix,primes.size()) { int x = primes[ix];
        vector<int> pp; for(auto p : primes) if (p != x) pp.push_back(p);
        DEBUG(x);
        REP(mask,TWO(24)) {
            ll prod = 1;
            REP(i,24) if (CONTAIN(mask,i)) prod *= pp[i];

            if (__builtin_popcount(mask) & 1) all += INF / prod / x;
            else all -= INF / prod / x;
        }
    }
    cout << "DONE 1" << endl;
    REP(ix,primes.size()) FOR(iy,ix+1,primes.size()-1) {
        int x = primes[ix], y = primes[iy];
        int xy = x * y;
        DEBUG(x);
        DEBUG(y);
        vector<int> pp; for(auto p : primes) if (p != x && p != y) pp.push_back(p);
        REP(mask,TWO(23)) {
            ll prod = 1;
            REP(i,23) if (CONTAIN(mask,i)) prod *= pp[i];

            if (__builtin_popcount(mask) & 1) all += INF / prod / xy;
            else all -= INF / prod / xy;
        }
    }
    cout << "DONE 2" << endl;
    REP(ix,primes.size()) FOR(iy,ix+1,primes.size()-1) FOR(iz,iy+1,primes.size()-1) {
        int x = primes[ix], y = primes[iy], z = primes[iz];
        int xyz = x*y*z;
        DEBUG(x);
        DEBUG(y);
        DEBUG(z);
        vector<int> pp; for(auto p : primes) if (p != x && p != y && p != z) pp.push_back(p);
        REP(mask,TWO(22)) {
            ll prod = 1;
            REP(i,22) if (CONTAIN(mask,i)) prod *= pp[i];

            if (__builtin_popcount(mask) & 1) all += INF / prod / xyz;
            else all -= INF / prod / xyz;
        }
    }

    DEBUG(all);
}

