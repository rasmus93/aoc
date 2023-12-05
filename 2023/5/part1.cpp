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

bool pred(const pair<ll, int> &i, const pair<ll, int> &j) {
    if (i.first == j.first) {
        return i.second > j.second;
    }
    return i.first < j.first;
}

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
vector<string> scan_strings(stringstream &ss, char delim) {
    string v;
    vector<string> res;
    while (getline(ss, v, delim)) {
        res.pb(v);
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
    vector<ll> a;
    ll v;
    while (cin >> v) {
        if (v == -1) {
            cin >> v >> v;
            break;
        }
        a.pb(v);
    }
    vector<vector<pt>> b(7);
    int cnt = 0;
    while (cin >> s >> s) {
        ll x, y, z;
        while (cin >> x >> y >> z) {
            if (x == -1) {
                break;
            }
            pt now{};
            now.from = y;
            now.to = x;
            now.range = z;
            b[cnt].pb(now);
        }
        ++cnt;
    }
    ll res = inf;
    FOR(i, a.size()) {
        ll now = a[i];
        FOR(j, 7) {
            FOR(k,b[j].size()) {
                if (now >= b[j][k].from && now <= b[j][k].from + b[j][k].range) {
                    ll add = now - (b[j][k].from);
                    now = b[j][k].to + add;
                    break;
                }
            }
        }
        res = min(res, now);
    }
    cout << res;
    return 0;
}