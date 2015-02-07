#include "template.h"

const int N = 11;
int a[N + 5];

int get(int x[]) {
    int a[N];
    REP(i,N) a[i] = x[i];
    int res = 0;
    REP(i,N) {
        if (a[i] == i) {
            continue;
        }
        if (a[N-1] == i) {
            reverse(a+i, a+N);
            res++;
        }
        else {
            FOR(j,i+1,N-2) if (a[j] == i) {
                reverse(a+j, a+N);
                reverse(a+i, a+N);
                res += 2;
            }
        }
    }
    return res;
}

void solve() {
    REP(i,N) a[i] = i;

    int best = -1, cnt = 0;
    do {
        int cur = get(a);
        if (cur > best) {
            best = cur;
            cnt = 1;
        }
        else if (cur == best) {
            ++cnt;
            if (cnt == 2011) {
                DEBUG(best);
                DEBUG(get(a));
                PR0(a, N);
                REP(i,N) cout << (char) (a[i] + 'A');
                cout << endl;
            }
        }
    } while (next_permutation(a, a+N));
}

