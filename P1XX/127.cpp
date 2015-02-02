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

const int MN = 120111;
int prod[MN], sieve[MN], minProd[MN];

void init() {
    FOR(i,2,1000) if (!sieve[i]) {
        for(int j = i*i; j < MN; j += i) {
            sieve[j] = i;
        }
    }
    FOR(i,1,MN-1) {
        if (!sieve[i]) prod[i] = i;
        else {
            int u = i;
            int p = sieve[i];
            while (u % p == 0) u /= p;
            prod[i] = p * prod[u];
        }
    }
    minProd[MN-1] = prod[MN-1];
    FORD(i,MN-2,1)
        minProd[i] = min(minProd[i+1], prod[i]);
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    init();
    long long res = 0;
    set< pair<int,int> > s;
    int a = 0;
    FOR(c,3,120000) {
        while (2*(a+1)+1 <= c) {
            ++a;
            s.insert(make_pair(prod[a], a));
        }
        int lim = c / prod[c];
        for(auto cur : s) {
            if (cur.first * 2 >= lim) break;
            if (__gcd(c, cur.second) == 1)
            if (cur.first * prod[c - cur.second] < lim) {
                res += c;
            }
        }
    }
    DEBUG(res);
    return 0;
}

