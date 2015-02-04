#include "template.h"

int f[211];
void solve() {
    vector<int> a;
    FOR(i,1,20) {
        a.push_back(i);
        a.push_back(2*i);
        a.push_back(3*i);
    }
    a.push_back(25);
    a.push_back(50);

    f[0] += 1;
    REP(i,a.size()) f[a[i]]++;
    REP(i,a.size()) FOR(j,i,a.size()-1)
        f[ a[i] + a[j] ]++;

    int sum = 0;
    FOR(score,2,99) {
        int cur = 0;
        FOR(i,1,20) if (2*i <= score) {
            cur += f[score - 2*i];

            if (score == 6) {
                cout << i << ' ' << cur << endl;
            }
        }
        if (50 <= score) cur += f[score - 50];

        sum += cur;
    }
    DEBUG(sum);
}

