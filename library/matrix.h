#include "template.h"

template< class T >
struct Matrix {
    int m, n;
    vector< vector<T> > values;

    Matrix(int m, int n) : m(m), n(n), values(m, vector<T> (n)) {}

    vector<T>& operator [] (int i) {
        ASSERT(0 <= i && i < m, "Row index outside range [0,m)");
        return values[i];
    }

    friend ostream& operator << (ostream& cout, const Matrix<T>& x) {
        cout << "Matrix " << x.m << "*" << x.n << endl;
        for(int i = 0; i < x.m; ++i) {
            for(int j = 0; j < x.n; ++j)
                cout << x.values[i][j] << ' ';
            cout << endl;
        }
        return cout;
    }

    Matrix<T> operator + (const Matrix<T>& a) {
        ASSERT(a.m == m && a.n == n, "Matrix operator + : Dimensions must be equal");
        Matrix<T> res(m, n);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j)
                res[i][j] = values[i][j] + a.values[i][j];
        }
        return res;
    }

    Matrix<T> operator - (const Matrix<T>& a) {
        ASSERT(a.m == m && a.n == n, "Matrix operator - : Dimensions must be equal");
        Matrix<T> res(m, n);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j)
                res[i][j] = values[i][j] - a.values[i][j];
        }
        return res;
    }

    Matrix<T> operator * (const Matrix<T>& a) {
        ASSERT(n == a.m, "Matrix opeartor * : no. col of first matrix must be equal to no. row of second matrix");
        Matrix<T> res(m, a.n);
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < a.n; ++j) {
                res.values[i][j] = 0;
                for(int k = 0; k < n; ++k)
                    res.values[i][j] = res.values[i][j] + values[i][k] * a.values[k][j];
            }
        return res;
    }

    Matrix<T> operator % (long long k) {
        ASSERT(m == n, "Matrix opeartor ** : only square matrix allowed");
        Matrix res = identity(m);
        Matrix cur = (*this);
        while (k > 0) {
            if (k & 1) res = res * cur;
            cur = cur * cur;
            k >>= 1;
        }
        return res;
    }

    Matrix<T> identity(int n) {
        Matrix<T> res(n, n);
        for(int i = 0; i < n; ++i)
            res.values[i][i] = 1;
        return res;
    }
};

