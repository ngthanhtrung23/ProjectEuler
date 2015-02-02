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

vector< vector<int> > f[12];
int res[211];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    f[0].push_back({1});
    memset(res, -1, sizeof res);
    res[1] = 0;
    int cnt = 1;

    FOR(turn,1,11) {
        for(auto cur : f[turn-1]) {
            set<int> has(cur.begin(), cur.end());

            REP(i,cur.size()) FOR(j,i,cur.size()-1) {
                if (!has.count(cur[i] + cur[j]) && cur[i] + cur[j] <= 200 && (res[cur[i] + cur[j]] < 0 || res[cur[i] + cur[j]] == turn)) {
                    vector<int> next = {cur};
                    next.push_back(cur[i] + cur[j]);
                    f[turn].push_back(next);

                    if (res[cur[i] + cur[j]] < 0) {
                        res[cur[i] + cur[j]] = turn;
                    }
                }
            }
        }
    }
    PR(res, 20);
    int sum = 0;
    FOR(i,1,200) {
        if (res[i] < 0) {
            DEBUG(i);
        }
        sum += res[i];
    }
    DEBUG(sum);
    return 0;
}

