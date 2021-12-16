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

ll get(VI &a, int from, int cnt) {
    ll res = 0;
    ll st = 1;
    for (int i = from + cnt - 1; i >= from; --i) {
        res += a[i] * st;
        st *= 2;
    }
    return res;
}

ll go(VI &a, int &i) {
    int packet_version = a[i] * 4 + a[i + 1] * 2 + a[i + 2] * 1;
    res += packet_version;
    int type_id = a[i + 3] * 4 + a[i + 4] * 2 + a[i + 5] * 1;
    i += 6;
    //cout << packet_version << " " << type_id << "\n";
    if (type_id == 4) {
        VI now;
        while (a[i] == 1) {
            ++i;
            REP(j,i,i + 4) {
                now.pb(a[j]);
            }
            i += 4;
        }
        ++i;
        REP(j,i,i + 4) {
            now.pb(a[j]);
        }
        i += 4;
        return get(now,0,now.size());
    } else {
        vector<ll> sub;
        if (a[i] == 0) {
            ++i;
            int len = get(a, i, 15);
            i += 15;
            int to = i + len;
            while (i < to) {
                sub.pb(go(a, i));
            }
        } else {
            ++i;
            int cnt = get(a, i, 11);
            i += 11;
            FOR(j, cnt) {
                sub.pb(go(a, i));
            }
        }
        if (type_id == 0) {
            ll now = 0;
            FOR(j,sub.size()) {
                now += sub[j];
            }
            return now;
        }
        if (type_id == 1) {
            ll now = sub[0];
            REP(j,1,sub.size()) {
                now *= sub[j];
            }
            return now;
        }
        if (type_id == 2) {
            ll now = sub[0];
            REP(j,1,sub.size()) {
                now = min(now, sub[j]);
            }
            return now;
        }
        if (type_id == 3) {
            ll now = sub[0];
            REP(j,1,sub.size()) {
                now = max(now, sub[j]);
            }
            return now;
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
    string z = "";
    FOR(i, s.size()) {
        char c = s[i];
        int v;
        if (c >= '0' && c <= '9') {
            v = c - '0';
        } else {
            v = c - 'A' + 10;
        }
        z += val[v];
    }
    int n = z.size();
    VI a(n);
    FOR(i, n) {
        a[i] = z[i] - '0';
    }
    int i = 0;
    cout << go(a, i) << " " << res;
    return 0;
}
