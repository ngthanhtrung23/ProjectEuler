import java.io.*;
import java.util.*;
import java.math.*;

public class P267 {
    public static void main(String[] args) {
        (new Solver()).go();
    }
}

class Solver {
    int N = 1000;
    BigInteger[][] c = new BigInteger[N + 5][N + 5];
    BigDecimal[] prob = new BigDecimal[N + 5];
    BigInteger p2_N = BigInteger.valueOf(2).pow(N);
    BigDecimal NEED = BigDecimal.valueOf(10).pow(9);

    public void go() {
        for(BigInteger[] row : c)
            Arrays.fill(row, BigInteger.ZERO);

        for(int i = 0; i <= N; ++i) {
            c[i][0] = BigInteger.ONE;
            for(int j = 1; j <= i; ++j)
                c[i][j] = c[i-1][j-1].add(c[i-1][j]);
        }

        for(int i = 0; i <= N; ++i)
            prob[i] = (new BigDecimal(c[N][i])).divide(new BigDecimal(p2_N), 20, BigDecimal.ROUND_HALF_UP);

        System.out.println("f(x) = " + f(0.16656954647474911));

        double l = 0.0, r = 1.0;
        BigDecimal res = BigDecimal.ZERO;
        for(int turn = 0; turn < 100; ++turn) {
            if (turn % 10 == 0) System.out.println("Range: " + l + ", " + r);
            double x1 = (l + l + r) / 3.0;
            double x2 = (l + r + r) / 3.0;
            BigDecimal y1 = f(x1), y2 = f(x2);

            if (y1.compareTo(y2) > 0) {
                r = x2;
                res = res.max(y1);
            }
            else {
                l = x1;
                res = res.max(y2);
            }
        }
        System.out.println("res = " + res);
    }

    BigDecimal f(double x) {
        BigDecimal res = BigDecimal.ZERO;
        for(int i = 0; i <= N; ++i) {
            BigDecimal value = BigDecimal.valueOf(1 + x + x).pow(i, new MathContext(20))
                .multiply(BigDecimal.valueOf(1 - x).pow(N - i, new MathContext(20)));

            if (value.compareTo(NEED) >= 0) {
                res = res.add(prob[i]);
            }
        }
        return res;
    }
}

