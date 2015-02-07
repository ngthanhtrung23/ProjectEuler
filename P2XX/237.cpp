#include "template.h"
#include "library/modulo.h"
#include "library/matrix.h"

const ll MOD = 1000 * 1000 * 100;

#define up(j,i) transition[i-1][j-1] = transition[i-1][j-1] + 1

void solve() {
    Matrix<Modulo<MOD>> start(6, 1);
    start[0][0] = Modulo<MOD>(2);
    start[3][0] = Modulo<MOD>(1);
    start[4][0] = Modulo<MOD>(1);

    Matrix<Modulo<MOD>> transition(6, 6);

    up(1, 3); up(1, 6);
    up(2, 2);
    up(3, 4); up(3, 5); up(3, 1); up(3, 1);
    up(4, 3);
    up(5, 5); up(5, 1); up(5, 1);
    up(6, 6); up(6, 3);

//    start = (transition % (1000LL * 1000 * 1000LL * 1000 - 2LL)) * start;
    start = (transition % 8) * start;
    cout << start << endl;
    cout << (start[2][0] + start[4][0]) << endl;
}

