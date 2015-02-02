import java.io.*;
import java.util.*;
import java.math.*;

public class P121 {
    public static void main(String[] args) {
        Fraction[][] f = new Fraction[16][16];
        for(int i = 0; i < 16; ++i)
            for(int j = 0; j < 16; ++j)
                    f[i][j] = new Fraction();

        f[0][0] = new Fraction(1, 1);
        for(int i = 0; i < 15; ++i) {
            for(int win = 0; win <= i; ++win) {
                f[i+1][win] = f[i+1][win].add(f[i][win].multiply(i+1).divide(i+2));
                f[i+1][win+1] = f[i+1][win+1].add(f[i][win].divide(i+2));
            }
        }
        Fraction res = new Fraction();
        for(int win = 0; win <= 15; ++win) {
            if (win > 15 - win) {
                res = res.add(f[15][win]);
                System.out.println(win);
            }
        }
        System.out.println(res);
    }
}

class Fraction {
    public BigInteger x, y;

    public Fraction() {
        x = BigInteger.ZERO;
        y = BigInteger.ONE;
    }

    public Fraction(int x, int y) {
        this.x = BigInteger.valueOf(x);
        this.y = BigInteger.valueOf(y);
    }

    public Fraction(BigInteger x, BigInteger y) {
        BigInteger g = x.gcd(y);
        this.x = x.divide(g);
        this.y = y.divide(g);
    }

    public Fraction add(Fraction a) {
        return new Fraction(
                x.multiply(a.y).add(y.multiply(a.x)),
                y.multiply(a.y)
                );
    }

    public Fraction divide(int k) {
        return new Fraction(
                x,
                y.multiply(BigInteger.valueOf(k))
                );
    }

    public Fraction multiply(int k) {
        return new Fraction(
                x.multiply(BigInteger.valueOf(k)),
                y
                );
    }

    public String toString() {
        return x.toString() + "/" + y.toString();
    }
}

