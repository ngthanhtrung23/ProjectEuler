/**
 * Rational number class template by igor
 * Stores and manipulates rational numbers represented by a pair
 * of integers of any type. This means that you can create
 * instances of Rational like this:
 *      - Rational< int > ri;
 *      - Rational< long long > rll;
 *      - Rational< BigInt > rbi;
 *
 * REQUIREMENTS on type T:
 *  - 0 and 1 must be valid parameters to T's constructor
 *  - all basic arithmetic operators must be defined for T
 *  - % (modulo operator) must be defined for T
 *
 * INVARIANTS:
 *      - the number is always stored in lowest terms
 *      - the denominator is always positive (###)
 *
 * (###) The denominator becomes 0 after dividing by zero
 *
 * FIELD TESTING:
 *      Passed these problems on Valladolid: 10113
 *
 * This file is part of my library of algorithms found here:
 *      http://www.palmcommander.com:8081/tools/
 * LICENSE:
 *      http://www.palmcommander.com:8081/tools/LICENSE.html
 * Copyright (c) 2004
 * Last modified: February 25, 2004
 * Contact author:
 *      igor at cs.ubc.ca
 **/


#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif

template< class T >
class Rational
{
    private:
        /** Greatest Common Divisor. **/
        static T gcd( const T &a, const T &b ) { return( a == T( 0 ) ? b : gcd( b % a, a ) ); }

        /** Reduces to lowest terms. **/
        inline void norm() { T g = gcd( n, d ); n /= g; d /= g; if( d < T( 0 ) ) { n = -n; d = -d; } }

        /** Creates a Rational without calling norm(). **/
        static inline Rational makeRat( const T &num, const T &denom )
        {
            Rational r( num );
            r.d = denom;
            return r;
        }

    public:
        /** Numerator and denominator. **/
        T n, d;

        /** Creates a new Rational number with value zero. **/
        Rational(): n( 0 ), d( 1 ) {}

        /** Creates a new Rational number with denominator 1. **/
        Rational( const T &num ): n( num ), d( 1 ) {}

        /** Creates a new Rational number with a given value. **/
        Rational( const T &num, const T &denom ): n( num ), d( denom ) { norm(); }

        /** Arithmetic. **/
        Rational< T > &operator++();
        Rational< T > &operator++( int );
        Rational< T > &operator--();
        Rational< T > &operator--( int );
        Rational< T >  operator- ();
        Rational< T >  operator+ ( const T &t    ) const;
        Rational< T >  operator+ ( const Rational< T > &r ) const;
        Rational< T > &operator+=( const T &t    );
        Rational< T > &operator+=( const Rational< T > &r );
        Rational< T >  operator- ( const T &t    ) const;
        Rational< T >  operator- ( const Rational< T > &r ) const;
        Rational< T > &operator-=( const T &t    );
        Rational< T > &operator-=( const Rational< T > &r );
        Rational< T >  operator* ( const T &t    ) const;
        Rational< T >  operator* ( const Rational< T > &r ) const;
        Rational< T > &operator*=( const T &t    );
        Rational< T > &operator*=( const Rational< T > &r );
        Rational< T >  operator/ ( const T &t    ) const;
        Rational< T >  operator/ ( const Rational< T > &r ) const;
        Rational< T > &operator/=( const T &t    );
        Rational< T > &operator/=( const Rational< T > &r );

        /** Comparision. **/
        bool operator< ( const Rational< T > &r ) const;
        bool operator> ( const Rational< T > &r ) const;
        bool operator<=( const Rational< T > &r ) const;
        bool operator>=( const Rational< T > &r ) const;
        bool operator==( const Rational< T > &r ) const;

        /** Casting and type conversion **/
        bool operator!() const;
        operator string() const;
        string toString() const;

        /** Outputs value to stdout **/
        void print() const;

};

template< class T > istream &operator>>( istream &in, const Rational< T > &n );
template< class T > ostream &operator<<( ostream &out, const Rational< T > &n );

template< class T >
Rational< T > &Rational< T >::operator++()
{
    Rational old = *this;
    n += d;
    return old;
}

template< class T >
Rational< T > &Rational< T >::operator++( int )
{
    n += d;
    return *this;
}

template< class T >
Rational< T > &Rational< T >::operator--()
{
    Rational old = *this;
    n -= d;
    return old;
}

template< class T >
Rational< T > &Rational< T >::operator--( int )
{
    n -= d;
    return *this;
}

template< class T >
Rational< T > Rational< T >::operator-()
{
    return makeRat( -n, d );
}

template< class T >
Rational< T > Rational< T >::operator+( const T &t ) const
{
    return makeRat( n + t * d, d );
}

template< class T >
Rational< T > Rational< T >::operator+( const Rational< T > &r ) const
{
    //FIXME: Can make this potentially slower but more robust against overflow
    return Rational< T >( n * r.d + d * r.n, d * r.d );
}

template< class T >
Rational< T > &Rational< T >::operator+=( const T &t )
{
    n += t * d;
    return *this;
}

template< class T >
Rational< T > &Rational< T >::operator+=( const Rational< T > &r )
{
    n *= r.d;
    n += d * r.n;
    d *= r.d;
    norm();
    return *this;
}

template< class T >
Rational< T > Rational< T >::operator-( const T &t ) const
{
    return makeRat( n - t * d, d );
}

template< class T >
Rational< T > Rational< T >::operator-( const Rational< T > &r ) const
{
    return Rational< T >( n * r.d - d * r.n, d * r.d );
}

template< class T >
Rational< T > &Rational< T >::operator-=( const T &t )
{
    n -= t * d;
    return *this;
}

template< class T >
Rational< T > &Rational< T >::operator-=( const Rational< T > &r )
{
    n *= r.d;
    n -= d * r.n;
    d *= r.d;
    norm();
    return *this;
}

template< class T >
Rational< T > Rational< T >::operator*( const T &t ) const
{
    T bc = gcd( t, d );
    return makeRat( n * ( t / bc ), d / bc );
}

template< class T >
Rational< T > Rational< T >::operator*( const Rational< T > &r ) const
{
    T ad = gcd( n, r.d ), bc = gcd( r.n, d );
    T rnbc = r.n / bc;
    T dbc = d / bc;
    T rdad = r.d / ad;
    return makeRat( (n / ad) * rnbc, dbc * rdad );
}

template< class T >
Rational< T > &Rational< T >::operator*=( const T &t )
{
    T bc = gcd( t, d );
    n *= t / bc;
    d /= bc;
    return *this;
}

template< class T >
Rational< T > &Rational< T >::operator*=( const Rational< T > &r )
{
    T ad = gcd( n, r.d ), bc = gcd( r.n, d );
    n /= ad;
    n *= r.n / bc;
    d /= bc;
    d *= r.d / ad;
    return *this;
}

template< class T >
Rational< T > Rational< T >::operator/( const T &t ) const
{
    T ac = gcd( n, t );
    return makeRat( n / ac, d * ( t / ac ) );
}

template< class T >
Rational< T > Rational< T >::operator/( const Rational< T > &r ) const
{
    T ac = gcd( n, r.n ), bd = gcd( d, r.d );
    return makeRat( ( n / ac ) * ( r.d / bd ), ( d / bd ) * ( r.n / ac ) );
}

template< class T >
Rational< T > &Rational< T >::operator/=( const T &t )
{
    T ac = gcd( n, t );
    n /= ac;
    d *= t / ac;
    return *this;
}

template< class T >
Rational< T > &Rational< T >::operator/=( const Rational< T > &r )
{
    T ac = gcd( n, r.n ), bd = gcd( d, r.d );
    n /= ac;
    n *= r.d / bd;
    d /= bd;
    d *= r.n / ac;
    return *this;
}

/** Comparison. **/
template< class T >
inline bool Rational< T >::operator< ( const Rational< T > &r ) const
{
    return n * r.d < d * r.n;
}

template< class T >
inline bool Rational< T >::operator> ( const Rational< T > &r ) const
{
    return n * r.d > d * r.n;
}

template< class T >
inline bool Rational< T >::operator<=( const Rational< T > &r ) const
{
    return n * r.d <= d * r.n;
}

template< class T >
inline bool Rational< T >::operator>=( const Rational< T > &r ) const
{
    return n * r.d >= d * r.n;
}

template< class T >
inline bool Rational< T >::operator==( const Rational< T > &r ) const
{
    return n == r.n && d == r.d;
}

/** Casting and type conversion **/
template< class T >
bool Rational< T >::operator!() const
{
    return n == T( 0 );
}

template< class T >
Rational< T >::operator string() const
{
    ostringstream out;
    out << n << " / " << d;
    return out.str();
}

template< class T >
string Rational< T >::toString() const
{
    return *this;
}

/** Outputs value to stdout **/
template< class T >
void Rational< T >::print() const
{
    cout << *this;
}

/** I/O Friends **/
template< class T >
istream &operator>>( istream &in, const Rational< T > &r )
{
    char slash;
    in >> r.n >> slash >> r.d;
    return in;
}

template< class T >
ostream &operator<<( ostream &out, const Rational< T > &r )
{
    return( out << ( string )r );
}
