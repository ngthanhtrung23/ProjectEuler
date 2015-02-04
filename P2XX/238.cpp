#include "template.h"

void solve() {
    unordered_map<int,int> s;
    int x = 14025256, pos = 0;
    stringstream buff;
    while (!s.count(x)) {
        s[x] = pos++;
        buff << x;
        x = (x * (ll) x) % 20300713;
        if (s.size() % 500000 == 0) DEBUG(s.size());
    }
    DEBUG(s.size());
    DEBUG(s[x]);

    string all = buff.str();
    DEBUG(all.size());
    DEBUG(all.substr(0, 20));
    DEBUG(all.substr(all.size()-20));

    long long sum_all = 0;
    for(auto c : all)
        sum_all += c - '0';

    DEBUG(sum_all);
}

