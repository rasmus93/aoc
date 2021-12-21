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

map<pair<pair<PII, PII>, int>, VI> m;

VI go(pair<PII, PII> v, int who) {
    auto vv = mp(v,who);
    if (m.count(vv)) {
        cout << v.first.first << " " << v.second.first << " "
             << v.first.second << " " << v.second.second << "\n";
        cout << m[vv][0] << " " << m[vv][1] << "\n";
        return m[vv];
    }
    VI now(2);
    
    if (who == 0) {
        FOR(i, add.size()) {
            int was = v.first.first;
            v.first.first += add[i];
            while (v.first.first > 10) {
                v.first.first -= 10;
            }
            v.first.second += v.first.first;
            if (v.first.second >= 21) {
                ++now[0];
            } else {
                VI next = go(v, 1);
                now[0] += next[0];
                now[1] += next[1];
            }
            v.first.second -= v.first.first;
            v.first.first = was;
        }
    } else {
        FOR(i, add.size()) {
            int was = v.second.first;
            v.second.first += add[i];
            while (v.second.first > 10) {
                v.second.first -= 10;
            }
            v.second.second += v.second.first;
            if (v.second.second >= 21) {
                ++now[1];
            } else {
                VI next = go(v, 0);
                now[0] += next[0];
                now[1] += next[1];
            }
            v.second.second -= v.second.first;
            v.second.first = was;
        }
    }
    m[vv] = now;
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
    VI res = go(mp(mp(a[0], 0), mp(a[1], 0)), 0);
    cout << res[0] << " " << res[1] << "\n";
    return 0;
}
