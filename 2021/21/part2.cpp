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
typedef vector<ll> VI;
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

VI add;

void pre() {
    REPE(i, 1, 3) {
        REPE(j, 1, 3) {
            REPE(k, 1, 3) {
                add.pb(i + j + k);
            }
        }
    }
}

map<pair<VPII, int>, VI> m;

VI go(VPII a, int who) {
    auto key = mp(a, who);
    if (m.count(key)) {
        return m[key];
    }
    VI now(2);
    FOR(i, add.size()) {
        VPII b = a;
        b[who].first += add[i];
        b[who].first = (b[who].first - 1) % 10 + 1;
        b[who].second += b[who].first;
        if (b[who].second >= 21) {
            ++now[who];
        } else {
            VI next = go(b, 1 - who);
            now[0] += next[0];
            now[1] += next[1];
        }
    }
    m[key] = now;
    return now;
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    VI a(2);
    a[0] = 4;
    a[1] = 8;
    /*a[0] = 7;
    a[1] = 6;*/
    pre();
    VPII b(2);
    FOR(i, 2) {
        b[i] = mp(a[i], 0);
    }
    VI res = go(b, 0);
    cout << res[0] << " " << res[1] << "\n";
    return 0;
}
