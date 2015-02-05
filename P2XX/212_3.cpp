#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
using namespace std;

ll S[300111];
vector< pair< pair<int,int>, pair<int,int> > > rects[10511];

struct Node {
    int cover_all, sum;
} it[100111];

#define CT(X) ((X) << 1)
#define CP(X) (CT(X) + 1)
void update(int i, int l, int r, int u, int v, int val) {
    if (v < l || r < u) return ;
    if (u <= l && r <= v) {
        it[i].cover_all += val;
        if (it[i].cover_all) {
            it[i].sum = r - l + 1;
        }
        else {
            it[i].sum = it[CT(i)].sum + it[CP(i)].sum;
        }
        return ;
    }
    int mid = (l + r) >> 1;
    update(CT(i), l, mid, u, v, val);
    update(CP(i), mid+1, r, u, v, val);
    if (it[i].cover_all == 0) it[i].sum = it[CT(i)].sum + it[CP(i)].sum;
}

vector< pair<int,int> > removes[10511], adds[10511];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(k,1,300000) {
        if (k <= 55) S[k] = (100003 - 200003 * k + 300007LL * k * k * k) % 1000000;
        else S[k] = (S[k-24] + S[k-55]) % 1000000;
    }

    FOR(i,1,50 * 1000) {
        int x0 = S[i*6-5] % 10000 + 1;
        int y0 = S[i*6-4] % 10000 + 1;
        int z0 = S[i*6-3] % 10000 + 1;
        int dx = S[i*6-2] % 399;
        int dy = S[i*6-1] % 399;
        int dz = S[i*6-0] % 399;

        FOR(x,x0,x0+dx)
            rects[x].push_back(make_pair(make_pair(y0, y0+dy), make_pair(z0, z0+dz)));
    }

    ll res = 0;
    FOR(x,1,10500) {
        FOR(y,1,10500) {
            adds[y].clear();
            removes[y].clear();
        }
        int nEvent = 0;
        memset(it, 0, sizeof it);
        for(auto r : rects[x]) {
            assert(r.second.second >= r.second.first);
            assert(r.first.second >= r.first.first);
            assert(10500 >= r.second.second);
            assert(10500 >= r.first.second);
            assert(1 <= r.second.first);
            assert(1 <= r.first.first);

            adds[r.first.first].push_back(make_pair(r.second.first, r.second.second));
            removes[r.first.second].push_back(make_pair(r.second.first, r.second.second));
        }
        FOR(y,1,10500) {
            for(auto p : adds[y]) {
                update(1, 1, 10500, p.first, p.second, +1);
            }
            res += it[1].sum;
            for(auto p : removes[y]) {
                update(1, 1, 10500, p.first, p.second, -1);
            }
        }
        assert(it[1].sum == 0);
        assert(it[1].cover_all == 0);
        if (x % 100 == 0) cout << x << ' ' << res << endl;
    }
    DEBUG(res);
    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

