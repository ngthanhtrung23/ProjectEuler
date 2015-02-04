#include "template.h"

long double a[88], sum[88];
const int N = 35;
int res = 0;
char tr[88];

int cmp(long double a, long double b) {
    if (fabs(a - b) < 1e-12) return 0;
    if (a < b) return -1;
    return 1;
}

void attempt(int i, long double cur) {
    if (i > N) {
        return ;
    }

    // Add
    long double next = cur + a[i];
    if (cmp(next, 0.5) == 0) {
        tr[i] = 'X';
        ++res;
        long double sum = 0.0;
        FOR(r,2,i) if (tr[r] == 'X') {
            cout << r << ' ';
            sum += a[r];
        }
        cout << endl;
        DEBUG(sum);
    }
    if (cmp(next + a[N], 0.5) <= 0) {
        tr[i] = 'X';
        attempt(i+1, next);
    }

    // Do nothing
    if (cmp(next + sum[i+1], 0.5) >= 0 && cmp(next + a[N], 0.5) <= 0) {
        tr[i] = '.';
        attempt(i+1, cur);
    }
}

void solve() {
    FORD(i,80,2) {
        a[i] = 1 / (long double) i / (long double) i;
        sum[i] = sum[i+1] + a[i];
    }
    attempt(2, 0);
    DEBUG(res);
}

