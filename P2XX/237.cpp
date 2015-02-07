#include "template.h"
#include "library/modulo.h"
#include "library/matrix.h"

const ll MOD = 1000 * 1000 * 100;

void solve() {
    Matrix<Modulo<MOD>> start(6, 1);
    start[0][0] = Modulo<MOD>(2);
    start[0][4] = Modulo<MOD>(1);

    cout << start << endl;

    Matrix<Modulo<MOD>> A(6, 6);
}

