#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for (int i=0; i<n; ++i)
#define FORE(i, n) for (int i=0; i<=n; ++i)
#define REP(i, a, b) for (int i=a; i<b; ++i)
#define REPE(i, a, b) for (int i=a; i<=b; ++i)
#define mp make_pair
#define pb push_back

typedef long double dbl;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;

bool pred(const int &i, const int &j) {
    return i < j;
}

bool contains(string &s, char c) {
    return s.find(c) != string::npos;
}

bool check(int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

string scan(stringstream &ss, char delim) {
    string v;
    getline(ss, v, delim);
    return v;
}

int scan_int(stringstream &ss, char delim) {
    return atoi(scan(ss, delim).c_str());
}

vector<string> scan_strings(stringstream &ss, char delim) {
    string v;
    vector<string> res;
    while (getline(ss, v, delim)) {
        res.pb(v);
    }
    return res;
}

vector<ll> scan_longs(stringstream &ss, char delim) {
    string v;
    vector<ll> res;
    while (getline(ss, v, delim)) {
        res.pb(atol(v.c_str()));
    }
    return res;
}

VI scan_ints(stringstream &ss, char delim) {
    string v;
    VI res;
    while (getline(ss, v, delim)) {
        res.pb(atoi(v.c_str()));
    }
    return res;
}

const int inf = -(int)1e9;

vector<vector<pair<PII, PII>>> all;
vector<bool> states;

ll solve_z(set<int> &used_y) {
    ll res = 0;
    set<int> used_z;
    int prev = -inf;

    VPII z;
    FOR(i,all.size()) {
        if (used_y.count(all[i][2].first.second)) {
            z.pb(all[i][2].first);
        }
        if (used_y.count(-all[i][2].second.second)) {
            z.pb(all[i][2].second);
        }
    }
    sort(z.begin(), z.end());
    FOR(i, z.size()) {
        PII now = z[i];
        if (!used_z.empty() && states[*used_z.rbegin() - 1]) {
            res += (now.first - prev);
        }
        prev = now.first;
        if (now.second > 0) {
            used_z.insert(now.second);
        } else {
            used_z.erase(-now.second);
        }
    }
    return res;
}

ll solve_y(set<int> &used_x) {
    ll res = 0;
    set<int> used_y;
    int prev = -inf;

    VPII y;
    FOR(i,all.size()) {
        if (used_x.count(all[i][1].first.second)) {
            y.pb(all[i][1].first);
        }
        if (used_x.count(-all[i][1].second.second)) {
            y.pb(all[i][1].second);
        }
    }
    sort(y.begin(), y.end());
    FOR(i,y.size()) {
        PII now = y[i];
        res += (now.first - prev) * solve_z(used_y);
        prev = now.first;
        if (now.second > 0) {
            used_y.insert(now.second);
        } else {
            used_y.erase(-now.second);
        }
    }
    return res;
}

ll solve_x() {
    ll res = 0;
    set<int> used;
    int prev = -inf;

    VPII x;
    FOR(i,all.size()) {
        x.pb(all[i][0].first);
        x.pb(all[i][0].second);
    }
    sort(x.begin(), x.end());
    FOR(i,x.size()) {
        PII now = x[i];
        res += (now.first - prev) * solve_y(used);
        prev = now.first;
        if (now.second > 0) {
            used.insert(now.second);
        } else {
            used.erase(-now.second);
        }
    }
    return res;
}


int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string state, s;
    int cnt = 1;
    while (cin >> state >> s) {
        stringstream ss(s);
        VI val;
        FOR(i, 3) {
            int v1,v2;
            char c;
            sscanf(scan(ss,',').c_str(),"%c=%d..%d",&c,&v1,&v2);
            val.pb(v1);
            val.pb(v2);
        }
        bool on = state == "on";
        states.pb(on);

        vector<pair<PII, PII>> pt(3);
        FOR(i,3) {
            pt[i].first = mp(val[i * 2], cnt);
            pt[i].second = mp(val[i * 2 + 1] + 1, -cnt);
        }
        all.pb(pt);
        ++cnt;
    }

    cout << solve_x();
    return 0;
}
