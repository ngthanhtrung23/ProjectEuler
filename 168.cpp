#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
using namespace std;

int a[111];

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    set<string> all;
    FOR(len,2,100) FOR(last,0,9) FOR(x,1,9) {
        a[len] = last;
        int rem = 0;
        FORD(i,len-1,0) {
            a[i] = (a[i+1] * x + rem) % 10;
            rem = (a[i+1] * x + rem) / 10;
        }
        if (rem == 0 && a[0] == a[len] && a[1] != 0) {
            stringstream ss; FOR(i,1,len) ss << a[i];
            string s = ss.str();
            DEBUG(s);
            all.insert(s);
        }
    }
    DEBUG(all.size());

    int sum = 0;
    for(string s : all) {
        string cur = (s.length() <= 5) ? s : s.substr(s.length()-5);
        stringstream ss; ss << cur;
        int k; ss >> k;
        sum = (sum + k) % 100000;
    }
    DEBUG(sum);

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

