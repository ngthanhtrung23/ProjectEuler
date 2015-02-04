#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
using namespace std;

ll S[300111];

struct Node {
    bool lazy;
    ll sz;
    Node *left, *right;

    Node(ll x1, ll x2, ll y1, ll y2, ll z1, ll z2) {
        lazy = false;
        sz = (x2 - x1 + 1LL) * (y2 - y1 + 1LL) * (z2 - z1 + 1LL);
        left = right = 0;
    }
} *root;

ll get(Node* root, ll x1, ll x2, ll y1, ll y2, ll z1, ll z2,
                   ll u1, ll u2, ll v1, ll v2, ll w1, ll w2, int rot) {
    if (u2 < x1 || x2 < u1) return 0;
    if (v2 < y1 || y2 < v1) return 0;
    if (w2 < z1 || z2 < w1) return 0;

    if (root->lazy) return 0;

    if (u1 <= x1 && x2 <= u2
            && v1 <= y1 && y2 <= v2
            && w1 <= z1 && z2 <= w2) {
        ll res = root->sz;
        root->sz = 0;
        root->lazy = true;
        return res;
    }
    ll res = 0;
    if (rot == 0) {
        int mx = (x1 + x2) / 2;
        if (!root->left) root->left = new Node(x1, mx, y1, y2, z1, z2);
        res += get(root->left, x1, mx, y1, y2, z1, z2, u1, u2, v1, v2, w1, w2, 1);

        if (!root->right) root->right = new Node(mx+1, x2, y1, y2, z1, z2);
        res += get(root->right, mx+1, x2, y1, y2, z1, z2, u1, u2, v1, v2, w1, w2, 1);
    }
    else if (rot == 1) {
        int my = (y1 + y2) / 2;
        if (!root->left) root->left = new Node(x1, x2, y1, my, z1, z2);
        res += get(root->left, x1, x2, y1, my, z1, z2, u1, u2, v1, v2, w1, w2, 2);

        if (!root->right) root->right = new Node(x1, x2, my+1, y2, z1, z2);
        res += get(root->right, x1, x2, my+1, y2, z1, z2, u1, u2, v1, v2, w1, w2, 2);
    }
    else {
        int mz = (z1 + z2) / 2;
        if (!root->left) root->left = new Node(x1, x2, y1, y2, z1, mz);
        res += get(root->left, x1, x2, y1, y2, z1, mz, u1, u2, v1, v2, w1, w2, 0);

        if (!root->right) root->right = new Node(x1, x2, y1, y2, mz+1, z2);
        res += get(root->right, x1, x2, y1, y2, mz+1, z2, u1, u2, v1, v2, w1, w2, 0);
    }
    root->sz = root->left->sz + root->right->sz;
    if (root->sz == 0) root->lazy = true;
    return res;
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    clock_t startTime = clock();

    FOR(k,1,300000) {
        if (k <= 55) S[k] = (100003 - 200003 * k + 300007LL * k * k * k) % 1000000;
        else S[k] = (S[k-24] + S[k-55]) % 1000000;
    }

    root = new Node(1, 10500, 1, 10500, 1, 10500);
    ll res = 0;
    FOR(i,1,50 * 1000) {
        int x0 = S[i*6-5] % 10000 + 1;
        int y0 = S[i*6-4] % 10000 + 1;
        int z0 = S[i*6-3] % 10000 + 1;
        int dx = S[i*6-2] % 399;
        int dy = S[i*6-1] % 399;
        int dz = S[i*6-0] % 399;

        res += get(root, 1, 10500, 1, 10500, 1, 10500, x0, x0+dx, y0, y0+dy, z0, z0+dz, 0);
        if (i % 10 == 0) cout << i << ' ' << res << endl;
    }

    cout << endl << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

