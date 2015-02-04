package P1XX;

import java.io.*;
import java.math.*;
import java.util.*;

public class P152 {
    public static void main(String[] args) {
        (new Solver()).go();
    }
}

class Solver {
    HashMap< BigInteger, Integer > count = new HashMap<>();
    HashMap< BigInteger, Integer > trace = new HashMap<>();
    int N = 46, res = 0, RIGHT = 20;
    BigInteger[] ii = new BigInteger[88];
    BigInteger[] sum = new BigInteger[88];
    BigInteger prod = BigInteger.ONE;
    int[] save = new int[88];

    boolean check(int u) {
        while (u % 2 == 0) u /= 2;
        while (u % 3 == 0) u /= 3;
        while (u % 5 == 0) u /= 5;
        while (u % 7 == 0) u /= 7;
        while (u % 13 == 0) u /= 13;
        return u == 1;
    }

    public void go() {
        int u = 1;
        for(int i = 2; i <= N; ++i) {
            u += 1;
            while (!check(u)) ++u;
            save[i] = u;
            ii[i] = BigInteger.valueOf(u*u);
            prod = prod.multiply(ii[i]);
        }
        System.out.println(save[N]);

        sum[N+1] = BigInteger.ZERO;
        for(int i = N; i >= 2; --i) {
            ii[i] = prod.divide(ii[i]);
            sum[i] = sum[i+1].add(ii[i]);
        }
        prod = prod.divide(BigInteger.valueOf(2));

        for(int mask = 0; mask < (1<<RIGHT); ++mask) {
            BigInteger sum = BigInteger.ZERO;
            for(int i = 0; i < RIGHT; ++i)
                if ((mask & (1<<i)) > 0) {
                    sum = sum.add(ii[i + N - RIGHT + 1]);
                }

            if (count.containsKey(sum)) count.put(sum, count.get(sum) + 1);
            else {
                count.put(sum, 1);
                trace.put(sum, mask);
            }
        }
        System.out.println("DONE INIT");

//        for(int mask = 0; mask < (1<<N-1-RIGHT); ++mask) {
//            BigInteger sum = BigInteger.ZERO;
//            for(int i = 0; i < N-1-RIGHT; ++i)
//                if ((mask & (1<<i)) > 0) {
//                    sum = sum.add(ii[i + 2]);
//                }
//            BigInteger need = prod.subtract(sum);
//            if (count.containsKey(need))
//                res = res + count.get(need);
//        }

        if (count.containsKey(prod))
            res = count.get(prod);
        attempt(0, BigInteger.ZERO);
        System.out.println("res = " + res);
    }

    int[] x = new int[88];
    int nx = 0;

    void attempt(int i, BigInteger cur) {
        if (i == N-1-RIGHT) {
            BigInteger need = prod.subtract(cur);
            if (count.containsKey(need)) {
                res = res += count.get(need);
                for(int t = 0; t < nx; ++t)
                    System.out.print(x[t] + ",");
                
                int mask = trace.get(need);
                for(int t = 0; t < RIGHT; ++t)
                    if ((mask & (1<<t)) > 0) {
                        System.out.print(save[t + N - RIGHT + 1] + ",");
                    }
                System.out.println();
            }

            return;
        }
        if (cur.add(sum[i+3]).compareTo(prod) >= 0)
            attempt(i + 1, cur);

        if (cur.add(ii[i+2]).compareTo(prod) <= 0) {
            x[nx++] = save[i+2];
            attempt(i + 1, cur.add(ii[i+2]));
            --nx;
        }
    }
}

