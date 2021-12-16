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

vector<ll> scan_ints(stringstream &ss, char delim) {
    string v;
    vector<ll> res;
    while (getline(ss, v, delim)) {
        res.pb(atol(v.c_str()));
    }
    return res;
}

string val[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011",
                  "1100", "1101", "1110", "1111"};

ll res = 0;

ll get(VI &a, int &from, int cnt) {
    ll res = 0;
    REP(i, from, from + cnt) {
        res <<= 1;
        res += a[i];
    }
    from += cnt;
    return res;
}

ll get(vector<ll> &sub, const function<ll(ll, ll)> &func) {
    ll now = sub[0];
    REP(j, 1, sub.size()) {
        now = func(now, sub[j]);
    }
    return now;
}

void get(VI &a, int &i, ll &now) {
    ++i;
    REP(j, i, i + 4) {
        now <<= 1;
        now += a[j];
    }
    i += 4;
}

ll go(VI &a, int &i) {
    int packet_version = get(a, i, 3);
    res += packet_version;
    int type_id = get(a, i, 3);
    //cout << packet_version << " " << type_id << "\n";
    if (type_id == 4) {
        ll now = 0;
        while (a[i] == 1) {
            get(a, i, now);
        }
        get(a, i, now);
        return now;
    } else {
        vector<ll> sub;
        if (a[i] == 0) {
            ++i;
            int len = get(a, i, 15);
            int to = i + len;
            while (i < to) {
                sub.pb(go(a, i));
            }
        } else {
            ++i;
            int cnt = get(a, i, 11);
            FOR(j, cnt) {
                sub.pb(go(a, i));
            }
        }
        if (type_id == 0) {
            return get(sub, [](ll x, ll y) -> ll { return x + y; });
        }
        if (type_id == 1) {
            return get(sub, [](ll x, ll y) -> ll { return x * y; });
        }
        if (type_id == 2) {
            return get(sub, [](ll x, ll y) -> ll { return min(x, y); });
        }
        if (type_id == 3) {
            return get(sub, [](ll x, ll y) -> ll { return max(x, y); });
        }
        if (type_id == 5) {
            return sub[0] > sub[1] ? 1 : 0;
        }
        if (type_id == 6) {
            return sub[0] < sub[1] ? 1 : 0;
        }
        if (type_id == 7) {
            return sub[0] == sub[1] ? 1 : 0;
        }
    }
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s;
    cin >> s;
    VI a;
    FOR(i, s.size()) {
        char c = s[i];
        int v;
        if (c >= '0' && c <= '9') {
            v = c - '0';
        } else {
            v = c - 'A' + 10;
        }
        FOR(i, val[v].size()) {
            a.pb(val[v][i] - '0');
        }
    }
    int i = 0;
    cout << go(a, i) << " " << res;
    return 0;
}
