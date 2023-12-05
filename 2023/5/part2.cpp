#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for (int i=0; i<n; ++i)
#define FORE(i, n) for (int i=0; i<=n; ++i)
#define REP(i, a, b) for (int i=a; i<b; ++i)
#define REPE(i, a, b) for (int i=a; i<=b; ++i)
#define mp make_pair
#define pb push_back

typedef long double dbl;
typedef long long int ll;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;


bool contains(string &s, char c) {
    return s.find(c) != string::npos;
}


string scan(stringstream &ss, char delim) {
    string v;
    getline(ss, v, delim);
    return v;
}

const ll inf = (ll) 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll myRand(ll B) {
    return (unsigned long long) rng() % B;
}

//stringstream ss(s);
//vector<string> values = scan_strings(ss, ',');
vector<string> scan_strings(string &s, char delim) {
    stringstream ss(s);
    string v;
    vector<string> res;
    while (getline(ss, v, delim)) {
        res.pb(v);
    }
    return res;
}

vector<ll> scan_lls(string &s, char delim) {
    stringstream ss(s);
    string v;
    vector<ll> res;
    while (getline(ss, v, delim)) {
        res.pb(atol(v.c_str()));
    }
    return res;
}

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool check(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

struct pt {
    ll from;
    ll to;
    ll range;
};


bool pred(const pt &i, const pt &j) {
    return i.from < j.from;
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
#ifdef DEBUG
    if (getenv("SUBMIT") == NULL) {
        freopen("local.txt", "r", stdin);
    } else {
        freopen("input.txt", "r", stdin);
    }
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s;
    cin >> s;
    cin.get();
    getline(cin, s);
    vector<ll> a = scan_lls(s, ' ');
    vector<vector<pt>> b(7);
    int cnt = 0;
    while (cin >> s >> s) {
        cin.get();
        while (getline(cin, s)) {
            if (s.empty()) {
                break;
            }
            vector<ll> v = scan_lls(s, ' ');
            b[cnt].pb(pt{v[1], v[0], v[2]});
        }
        ++cnt;
    }
    FOR(i, cnt) {
        b[i].pb(pt{-1, -1, 0});
        b[i].pb(pt{inf, inf, 0});
        sort(b[i].begin(), b[i].end(), pred);
    }
    ll res = inf;
    for (int i = 0; i < a.size(); i += 2) {
        cerr << i << "\n";
        for (ll val = a[i]; val <= a[i] + a[i + 1]; ++val) {
            ll now = val;
            FOR(j, 7) {
                auto it = upper_bound(b[j].begin(), b[j].end(), now,
                                      [](ll value, const pt &p) {
                                          return value < p.from;
                                      });
                int k = (int) (it - b[j].begin()) - 1;
                if (now >= b[j][k].from && now <= b[j][k].from + b[j][k].range) {
                    ll add = now - (b[j][k].from);
                    now = b[j][k].to + add;
                }
            }
            res = min(res, now);
        }
    }
    cout << res;
    return 0;
}