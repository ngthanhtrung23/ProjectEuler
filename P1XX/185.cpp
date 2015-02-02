#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

#define DEBUG(x) { cout << #x << " = "; cout << (x) << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define hash _hash
using namespace std;

int n;
char tmp[100111];
pair<string,int> a[111];
map< long long, string > hash;

long long encode(vector<int> &a) {
    long long res = 0;
    REP(i,a.size()) res = (res * 17 + a[i]);
    return res;
}

string cur = "xxx";
clock_t startTime;

void gen(int i, int min_id, int max_id, bool store, string s, vector<int> wrong) {
    if (i == max_id) {
        if (s[0] != cur[0] || s[1] != cur[1]) {
            cur = "";
            cur += s[0];
            cur += s[1];
            cout << "At: " << cur << ' ' << hash.size() << endl;
        }
        if (store) {
            REP(j,n)
                wrong[j] = a[j].second - wrong[j];
            hash[encode(wrong)] = s;
        }
        else {
            if (hash.count(encode(wrong))) {
                cout << hash[encode(wrong)] << s << endl;
                cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
                exit(0);
            }
        }
        return ;
    }
    FOR(cur,'0','9') {
        bool ok = true;
        REP(j,n) if (a[j].first[i] != cur) {
            ++wrong[j];
            if (wrong[j] > a[j].second || wrong[j] + a[0].first.size() - (i - min_id + 1) < a[j].second) {
                ok = false;
            }
        }

        if (ok) {
            string t = s;
            t += (char) cur;
            gen(i+1, min_id, max_id, store, t, wrong);
        }

        REP(j,n) if (a[j].first[i] != cur) --wrong[j];
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cout << (fixed) << setprecision(6);
    startTime = clock();

    freopen("input.txt", "r", stdin);
    n = 0;
    while (gets(tmp)) {
        REP(i,strlen(tmp)) if (tmp[i] == ';') tmp[i] = ' ';
        istringstream ss(tmp);
        ss >> a[n].first >> a[n].second;
        a[n].second = a[n].first.length() - a[n].second;
        ++n;
    }

    REP(i,n) cout << a[i].first << ' ' << a[i].second << endl;

    int BOUND1 = 8, BOUND2 = 16;
    vector<int> wrong;
    REP(i,n) wrong.push_back(0);

    gen(0, 0, BOUND1, true, "", wrong);
    cout << "DONE STEP 1" << endl;
    DEBUG(hash.size());

    wrong.clear();
    REP(i,n) wrong.push_back(0);
    gen(BOUND1, BOUND1, BOUND2, false, "", wrong);
    cout << "DONE STEP 2" << endl;

    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}

