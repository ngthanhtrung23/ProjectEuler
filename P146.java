import java.io.*;
import java.math.*;
import java.util.*;

public class P146 {
    public static void main(String[] args) {
        long sum = 0;
        for(long i = 10; i < 150 * 1000000; i += 10)
        if (i % 3 > 0)
        if (i % 7 == 3 || i % 7 == 4) {
            if (i % 1000000 == 0) {
                System.out.println("i = " + i);
            }
            long ii = i*i;
            boolean ok = true;
            int[] t = {1, 3, 7, 9, 13, 27};
            for(int val : t) {
                if (!BigInteger.valueOf(ii + val).isProbablePrime(100)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            t = new int[]{11,17,21,23};
            for(int val : t) {
                if (BigInteger.valueOf(ii + val).isProbablePrime(100)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            System.out.println(i);
            sum += i;
        }
        System.out.println("sum = " + sum);
    }
}
