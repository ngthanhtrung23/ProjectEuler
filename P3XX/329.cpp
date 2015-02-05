#include "template.h"
#include "library/RabinMiller.h"
#include "library/bigint.h"
#include "library/rational.h"

string seq = "PPPPNNPPPNPPNPN";
Rational<BigInt> f[20][511];

void solve() {
    FOR(i,1,500) f[0][i] = Rational<BigInt> (1, 500);
    auto r2_3 = Rational<BigInt> (2, 3);
    auto r1_3 = Rational<BigInt> (1, 3);
    auto r1_2 = Rational<BigInt> (1, 2);

    REP(turn,15) {
        DEBUG(turn);
        FOR(i,1,500) {
            if (i == 1) {
                if (seq[turn] == 'N') f[turn+1][i+1] += f[turn][i] * r2_3;
                else f[turn+1][i+1] += f[turn][i] * r1_3;
            }
            else if (i == 500) {
                if (seq[turn] == 'N') f[turn+1][i-1] += f[turn][i] * r2_3;
                else f[turn+1][i-1] += f[turn][i] * r1_3;
            }
            else {
                if (!isPrime(i)) {
                    if (seq[turn] == 'N') {
                        f[turn+1][i-1] += f[turn][i] * r1_2 * r2_3;
                        f[turn+1][i+1] += f[turn][i] * r1_2 * r2_3;
                    }
                    else {
                        f[turn+1][i-1] += f[turn][i] * r1_2 * r1_3;
                        f[turn+1][i+1] += f[turn][i] * r1_2 * r1_3;
                    }
                }
                else {
                    if (seq[turn] == 'P') {
                        f[turn+1][i-1] += f[turn][i] * r1_2 * r2_3;
                        f[turn+1][i+1] += f[turn][i] * r1_2 * r2_3;
                    }
                    else {
                        f[turn+1][i-1] += f[turn][i] * r1_2 * r1_3;
                        f[turn+1][i+1] += f[turn][i] * r1_2 * r1_3;
                    }
                }
            }
        }
    }
    auto res = Rational<BigInt> (0, 1);
    FOR(i,1,500) res = res + f[15][i];
    cout << res << endl;
}

