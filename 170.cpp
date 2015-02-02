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

int mark[10];
int b[10];

bool attempt(int mult, int i, long long cur, vector<long long>& x) {
    bool equal = true;

    REP(t,10)
        if (b[t] != "9768352140" [t] - '0') equal = false;

    if (i == 10) {
        if (!cur && x.size() > 1) {
            REP(d,10) if (mark[d] != 1) return false;
            DEBUG(cur);
            PR0(x, x.size());
            cout << "x/mult = "; for(auto t : x) cout << t / mult << ' '; cout << endl;
            return true;
        }
        return false;
    }
    // Add & continue
    cur = cur * 10 + b[i];
    if (attempt(mult, i + 1, cur, x)) return true;

    // Split
    if (cur % mult == 0) {
        long long u = cur / mult;
        bool ok = true;
        do {
            mark[u % 10] += 1;
            if (mark[u % 10] > 1) {
                ok = false;
            }
            u /= 10;
        } while (u);
        x.push_back(cur);
        if (equal && mult == 9 && cur == 9) {
            PR0(b, 10);
            DEBUG(i);
            PR0(x, x.size());
            DEBUG(u);
            DEBUG(ok);
        }

        if (ok && attempt(mult, i + 1, 0, x)) return true;
        
        x.pop_back();
        u = cur / mult;
        do {
            mark[u % 10] -= 1;
            u /= 10;
        } while (u);
    }
    return false;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    int rev_b[10];
    REP(i,10) rev_b[i] = i;
    int turn = 0;
    do {
        REP(i,10) b[i] = 9 - rev_b[i];
        if (b[0] != 9) break;
        FOR(mult,2,99) {
            memset(mark, 0, sizeof mark);
            int u = mult;
            bool ok = true;
            while (u) {
                mark[u % 10]++;
                if (mark[u %10] > 1) ok = false;

                u /= 10;
            }
            if (!ok) continue;

            vector<long long> x;
            if (attempt(mult, 0, 0, x)) {
                REP(i,10) cout << b[i];
                cout << endl;
                DEBUG(mult);
                exit(0);
                break;
            }
        }
        ++turn;
        if (turn % 100000 == 0) DEBUG(turn);
    } while (next_permutation(rev_b, rev_b+10));

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

