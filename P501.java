import java.io.*;
import java.util.*;
import java.math.*;

public class P501 {
    public static void main(String[] args) {
        (new Solver()).go();
    }
}

class Solver {
    public Solver() {
        piLookup.put(0L, 0L);
    }

    public void go() {
        init();

        long INF = 1000L * 1000 * 1000 * 1000;

        long res = 0;
        for(long i = 2; i*i*i * i*i*i*i <= INF; ++i)
            if (isPrime(i)) 
                ++res;

        for(long i = 2; i*i*i <= INF; ++i) if (isPrime(i)) {
            long bound = INF / i / i / i;
            res += primePi(bound);
            if (bound >= i) --res;
        }

        for(long i = 2; i*i <= INF; ++i)
            if (isPrime(i)) {
                long bound = Math.min(i - 1, INF / i / i);
                for(int j = 2; j <= bound; ++j)
                    if (isPrime(j)) {
                        long cur = INF / i / j;
                        if (cur >= i)
                            res += primePi(cur) - primePi(i);
                    }
            }
        System.out.println(INF / 8);
        System.out.println(INF / 6);
        System.out.println("primeRange = " + primeRange);
        System.out.println("res = " + res);
    }

    boolean isPrime(long n) {
        if (n < MN) return sieve[(int) n] == 0;
        else return BigInteger.valueOf(n).isProbablePrime(100);
    }


    final int MN = 1000111;
    int[] sieve = new int[MN];
    int[] pi = new int[MN];
    void init() {
        for(int i = 2; i <= 2000; ++i) if (sieve[i] == 0) {
            for(int j = i*i; j < MN; j += i) {
                sieve[j] = i;
            }
        }

        long sum = 0;
        for(int i = 2; i < MN; ++i) {
            pi[i] = pi[i-1];
            if (sieve[i] == 0) ++pi[i];
        }

        load("PI_1011_1012.txt");
        load("PI_1010_1011.txt");
        load("PI_1009_1010.txt");
        load("PI_1008_1009.txt");
        load("PI_1007_1008.txt");
        load("PI_1006_1007.txt");
    }

    long primeRange = 0;
    TreeMap<Long,Long> piLookup = new TreeMap<>();

    void load(String filename) {
        System.out.println("Load pi lookup from: " + filename);
        try (Scanner sc = new Scanner(new File(filename))) {
            while (sc.hasNext()) {
                long n = sc.nextLong();
                long pi = sc.nextLong();
                piLookup.put(n, pi);
            }
        }
        catch (Exception ex) {
        }
    }

    long primePi(long n) {
        if (n < MN) return pi[(int) n];
        Map.Entry<Long,Long> floor = piLookup.floorEntry(n);
        if (n - floor.getKey() > 100011100L) {
            System.out.println("n = " + n);
            System.exit(0);
        }
        return floor.getValue() + primeRange(floor.getKey() + 1, n);
    }
    long primeRange(long l, long r) {
        if (r < MN) {
            return pi[(int) r] - pi[(int) l];
        }
        long res = 0;
        primeRange += r - l + 1;
        if (l < 2) l = 2;
        if (l == 2) {
            res = 1;
            l++;
        }
        for(long i = l; i <= r; i += 2)
            if (isPrime(i))
                ++res;
        return res;
    }
}

