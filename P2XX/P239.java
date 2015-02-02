import java.io.*;
import java.math.*;
import java.util.*;

public class P239 {
    public static void main(String[] args) {
        int cnt = 0;
        for(int i = 1; i <= 100; ++i)
            if (BigInteger.valueOf(i).isProbablePrime(100)) {
                ++cnt;
            }
        System.out.println("cnt = " + cnt);
        // 1 --> 100: 25 primes, 75 composites
        // 22 prime are at wrong positions --> 3 primes are at correct position
        // First, choose what primes are correct --> C(25, 3)
        // Now we're left with 22 primes and 75 composites. These 22 primes must all be at wrong positions
        // while 75 composites can be placed at any position.

        // Use inclusion-exclusion theorem:
        // Number of configurations such that all 22 primes are at wrong positions
        // = (number of any configurations)
        //   - (number of configurations such that at least 1 prime is at correct position)
        //   + (number of configurations such that at least 2 primes are at correct positions)
        //   - (number of configurations such that at least 3 primes are at correct positions)
        //   ...

        BigInteger[][] c = new BigInteger[111][111];
        for(int i = 0; i < 111; ++i) {
            for(int j = 0; j < 111; ++j)
                c[i][j] = BigInteger.ZERO;

            c[i][0] = BigInteger.ONE;
            for(int j = 1; j <= i; ++j)
                c[i][j] = c[i-1][j-1].add(c[i-1][j]);
        }

        BigInteger[] factorial = new BigInteger[111];
        factorial[0] = BigInteger.ONE;
        for(int i = 1; i < 111; ++i)
            factorial[i] = factorial[i-1].multiply(BigInteger.valueOf(i));

        BigInteger res = BigInteger.ZERO;
        for(int correct = 0; correct <= 22; ++correct) {
            BigInteger cur = c[22][correct].multiply(factorial[22 + 75 - correct]);
            if (correct % 2 == 0) {
                res = res.add(cur);
            }
            else {
                res = res.subtract(cur);
            }
        }
        res = res.multiply(c[25][3]);

        BigDecimal t = new BigDecimal(res);
        t = t.divide(new BigDecimal(factorial[100]), 12, BigDecimal.ROUND_HALF_UP);
        System.out.println(t);
    }
}

