ll _private_mult(ll a, ll b, ll MOD) {
    if (b == 0) return 0;
    if (a <= 1000111000111000111LL / b) return (a * b) % MOD;

    ll mid = _private_mult(a, b >> 1, MOD);
    mid = (mid + mid) % MOD;
    if (b & 1) return (mid + a) % MOD;
    else return mid;
}
template <long long MOD>
struct Modulo {
    long long value;

    Modulo(long long val = 0) { value = (val % MOD + MOD) % MOD; }

    Modulo operator + (const Modulo& a) const { return Modulo((value + a.value) % MOD); }
    Modulo operator - (const Modulo& a) const { return Modulo((value - a.value + MOD) % MOD); }
    Modulo operator * (const Modulo& a) const {
        return Modulo(_private_mult(value, a.value, MOD));
    }
    bool operator == (const Modulo& a) const { return value == a.value; }

    void operator += (const Modulo& a) { value = (value + a.value) % MOD; }
    void operator -= (const Modulo& a) { value = (value - a.value + MOD) % MOD; }
    void operator *= (const Modulo& a) {
        value = _private_mult(value, a.value, MOD);
    }

    friend ostream& operator << (ostream& cout, const Modulo<MOD>& x) {
        cout << x.value;
        return cout;
    }
    friend istream& operator >> (istream& cin, Modulo<MOD>& x) {
        cin >> x.value;
        return cin;
    }
};

template <long long MOD>
Modulo<MOD> power(Modulo<MOD> x, long long k) {
    if (k == 0) return 1;
    if (k == 1) return x;
    auto mid = power(Modulo<MOD>(
                _private_mult(x.value, x.value, MOD)), k >> 1);

    if (k & 1) return _private_mult(mid.value, x.value, MOD);
    else return mid;
}

