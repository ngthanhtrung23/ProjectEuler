#include "template.h"
#include "library/bigint.h"
#include "library/RabinMiller.h"

const ll INF = (ll) (1e16);
ll c[111][111];
vector<int> primes;
ll all;

void attempt(int i, ll prod, int cnt) {
    if (i == primes.size()) {
        ll div = INF / prod;

        if (cnt & 1) {
            all += div * (1LL - cnt + c[cnt][2] - c[cnt][3]);
        }
        else {
            all -= div * (1LL - cnt + c[cnt][2] - c[cnt][3]);
        }
        return ;
    }

    attempt(i+1, prod, cnt);
    if (prod * primes[i] <= INF)
        attempt(i+1, prod * primes[i], cnt + 1);
}

void solve() {
    FOR(i,0,100) {
        c[i][0] = 1;
        FOR(j,1,i)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
    DEBUG(INF);
    FOR(i,2,100) if (isPrime(i)) primes.push_back(i);
    DEBUG(primes.size());
    PR0(primes, primes.size());

    all = INF;

    attempt(0, 1, 0);

    DEBUG(all);

//    int res = 0;
//    FOR(i,1,INF) {
//        int cnt = 0;
//        for(auto p : primes)
//            if (i % p == 0) ++cnt;
//
//        if (cnt >= 4) ++res;
//    }
//    DEBUG(res);
}

