#include "template.h"
#include "library/RabinMiller.h"
#include "library/bigint.h"

#define TWO(X) (1<<(X))
#define CONTAIN(S,X) (S & TWO(X))

BigInt sqrt(BigInt n) {
    BigInt l = 1, r = n / 2;
    BigInt res = l;

    while (l <= r) {
        BigInt mid = (l + r) / BigInt(2);
        if (mid * mid <= n) {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    return res;
}

void solve() {
    vector<int> primes;
    FOR(i,2,190) if (isPrime(i)) {
        primes.push_back(i);
    }
    DEBUG(primes.size());
    PR0(primes, primes.size());

    BigInt all = 1;
    for(auto p : primes)
        all = all * p;

    DEBUG(all);

    BigInt bound = sqrt(all);
    DEBUG(bound);

    vector<BigInt> left;
    REP(mask,TWO(21)) {
        BigInt prod = 1;
        REP(i,21) if (CONTAIN(mask,i)) prod = prod * primes[i];

        left.push_back(prod);
    }
    cerr << "DONE GENERATING" << endl;
    sort(left.begin(), left.end());
    cerr << "DONE SORTING" << endl;

    BigInt res = 1;
    PR0(left, 10);
    REP(mask,TWO(21)) {
        BigInt prod = 1;
        REP(i,21) if (CONTAIN(mask,i)) prod = prod * primes[i + 21];

        if (prod > bound) continue;

        BigInt need = bound / prod;
        if (need >= left.back()) res = max(res, left.back() * prod);
        else {
            auto it = upper_bound(left.begin(), left.end(), need);
            --it;
            BigInt cur = (*it) * prod;
            if (cur > res) {
                res = cur;
                cout << "  res = " << res << ' ' << res % BigInt(10000000000000000LL) << endl;
            }
        }

        if (mask % 1000 == 0) {
            cout << mask * 100.0 / (double) (1<<21) << endl;
        }
    }
    DEBUG(res);
}

