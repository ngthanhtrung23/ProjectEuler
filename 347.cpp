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

const int N = 10 * 1000 * 1000;
int sieve[10111000];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(i,2,4000) if (!sieve[i]) {
        for(int j = i*i; j < 10111000; j += i)
            sieve[j] = i;
    }

    long long res = 0;
    set< pair<int,int> > all;
    FORD(i,N,2) if (sieve[i]) {
        int u = i;
        int p1 = sieve[u];
        while (u % p1 == 0) u /= p1;

        if (u == 1) continue;

        int p2 = sieve[u] ? sieve[u] : u;
        while (u % p2 == 0) u /= p2;

        if (u != 1) continue;

        if (p1 > p2) swap(p1, p2);
        if (all.count(make_pair(p1, p2))) continue;
        if (i * (long long) p2 <= N || i * (long long) p1 <= N) continue;

        res += i;
        all.insert(make_pair(p1, p2));
    }
    DEBUG(res);

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

