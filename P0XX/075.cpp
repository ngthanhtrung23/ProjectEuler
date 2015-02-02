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

map<int,int> cnt;

void genPytTriples(int n) {
    for (int r=1; r*r<=n; ++r) for (int s=(r%2==0)?1:2; s<r; s+=2) if (__gcd(r,s)==1) {
        vector<int> t,h;
        t.push_back(r*r+s*s); //z 
        t.push_back(2*r*s); // y
        t.push_back(r*r-s*s); // x
        h=t;
        while (h[0]<=n) {
            int sum = h[0] + h[1] + h[2];
            if (sum <= 1500000) {
                cnt[sum] += 1;
            }
            h[0]+=t[0]; h[1]+=t[1]; h[2]+=t[2];            
        }
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(9);
    genPytTriples(1500000 / 2);
    int res = 0;
    for(auto e : cnt)
        if (e.second == 1)
            res++;
    cout << res << endl;
    return 0;
}

