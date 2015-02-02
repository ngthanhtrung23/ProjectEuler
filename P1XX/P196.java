import java.io.*;
import java.util.*;
import java.math.*;

public class P196 {
    public static void main(String[] args) {
        System.out.println(get(5678027) + get(7208785));
    }

    static int get(int row) {
        long[] a = getRow(row - 1);
        long[] b = getRow(row);
        long[] c = getRow(row + 1);

        boolean[] good = new boolean[row];
        for(int i = 0; i < row; ++i) {
            if (isPrime(b[i])) {
                int cnt = 0;
                if (i > 0 && isPrime(a[i-1])) ++cnt;
                if (i < a.length && isPrime(a[i])) ++cnt;
                if (i+1 < a.length && isPrime(a[i+1])) ++cnt;

                if (i > 0 && isPrime(b[i-1])) ++cnt;
                if (i+1 < b.length && isPrime(b[i+1])) ++cnt;

                if (i > 0 && isPrime(c[i-1])) ++cnt;
                if (i < c.length && isPrime(c[i])) ++cnt;
                if (i+1 < c.length && isPrime(c[i+1])) ++cnt;

                if (cnt >= 2) good[i] = true;
            }
            if (i % 100000 == 0) System.out.println(i);
        }

        int res = 0;
        for(int i = 0; i < row; ++i) {
            if (good[i]) {
                res += b[i];
            }
        }
        System.out.println("get " + row + " --> " + res);
        return res;
    }

    static long[] getRow(int row) {
        long[] res = new long[row];
        long start = sumUp(row-1) + 1;

        for(int i = 0; i < res.length; ++i) {
            res[i] = start++;
        }

        System.out.println("Done gen row: " + row);

        return res;
    }

    static long sumUp(long n) {
        return n * (n + 1L) / 2;
    }

    static boolean isPrime(long n) {
        if (n % 2 == 0) return false;
        return BigInteger.valueOf(n).isProbablePrime(100);
    }
}
