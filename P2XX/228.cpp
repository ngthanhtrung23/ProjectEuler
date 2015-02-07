#include "template.h"
#include "library/geometry.h"

Polygon a[2011];

int FROM = 1864;
int TO = 1909;

void solve() {
    FOR(n,FROM,TO) {
        FOR(k,1,n) {
            double alpha = DEG_TO_RAD((2*k-1) / (double) n * 180);
            a[n].push_back(Point(cos(alpha), sin(alpha)));
        }
    }
    Polygon cur = a[FROM];
    FOR(i,FROM + 1,TO) {
        Polygon next;
        for(auto P : cur)
            for(auto Q : a[i])
                next.push_back(P + Q);

        DEBUG(next.size());

        Point A = next[0], B = next[0], C = next[0], D = next[0];

        for(auto P : next) {
            if (P.x < A.x) A = P;
            if (P.x > C.x) C = P;
            if (P.y < B.y) B = P;
            if (P.y > D.y) D = P;
        }
        Polygon bound {A, B, C, D};
        for(auto P : next)
            if (!in_polygon(bound, P))
                cur.push_back(P);

        DEBUG(cur.size());
        cur = convex_hull(next);
        cout << i << ' ' << cur.size() << endl;
    }
}

