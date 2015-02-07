template< class T >
struct Matrix {
    int m, n;
    vector< vector<T> > values;

    Matrix(int m, int n) : m(m), n(n), values(m, vector<T> (n)) {}

    vector<T>& operator [] (int i) {
        return values[i];
    }

    friend ostream& operator << (ostream& cout, const Matrix<T>& x) {
        for(int i = 0; i < x.m; ++i) {
            for(int j = 0; j < x.n; ++j)
                cout << x.values[i][j] << ' ';
            cout << endl;
        }
    }
};

