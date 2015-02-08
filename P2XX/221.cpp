#include "template.h"

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    ordered_set all;
    FOR(p,1,90000) {
        if (p % 10000 == 0) {
            DEBUG(p);
            cout << *all.find_by_order(150 * 1000 - 1) << endl;
            cout << *all.find_by_order(150 * 1000) << endl;
            cout << *all.find_by_order(150 * 1000 + 1) << endl;
        }
        ll pp1 = p*(ll)p + 1;
        for(ll d = 1; d*d <= pp1; ++d)
            if (pp1 % d == 0) {
                ll x = p;
                ll y = p + d;
                ll z = p + pp1 / d;

                if (x * y > 1000111000111000111LL / z) continue;

                assert(y*z - x*y - x*z == 1);

                ll cur = x * y * z;
                all.insert( x * y * z );
                if (all.size() > 155000) all.erase(all.end());
            }
    }
}

