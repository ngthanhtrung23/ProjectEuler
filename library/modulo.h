template <size_t MOD>
struct Modulo {
    long long value;

    Modulo(long long val = 0) : value(val % MOD) {}

    Modulo operator + (Modulo a) { return Modulo((value + a.value) % MOD); }
    Modulo operator - (Modulo a) { return Modulo((value - a.value + MOD) % MOD); }
    Modulo operator * (Modulo a) { return Modulo((value * a.value) % MOD); }

    friend ostream& operator << (ostream& cout, const Modulo<MOD>& x) {
        cout << x.value;
        return cout;
    }
    friend istream& operator >> (istream& cin, Modulo<MOD>& x) {
        cin >> x.value;
        return cin;
    }
};

