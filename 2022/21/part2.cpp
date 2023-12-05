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

bool check(int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

string scan(stringstream &ss, char delim) {
    string v;
    getline(ss, v, delim);
    return v;
}

const int inf = (int) 1e9;

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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
//x >= 0 && y >= 0 && x < n && y < m

map<string, int> m;

struct pt {
    ll v;
    int x, y;
    string op = "z";
};

map<int,pt> g;

int get_num(string &s, int &n) {
    if (m.count(s)) {
        return m[s];
    }
    m[s] = n;
    ++n;
    return m[s];
}

bool ok = false;
ll xx = -1;
ll yy = -1;

ll go(int v, bool div) {
    if (g[v].op == "z") {
        return g[v].v;
    }
    ll x = go(g[v].x, div);
    ll y = go(g[v].y, div);
    if (x == -1 || y == -1) {
        return -1;
    }
    if (v == m["root"]) {
        cerr << x << " " << y << "\n";
        if (x == y) {
            ok = true;
        }
        xx = x;
        yy = y;
    }
    ll res = 0;
    if (g[v].op == "*") {
        res = x * y;
    } else if (g[v].op == "+") {
        res = x + y;
    } else if (g[v].op == "-") {
        res = x - y;
    } else if (g[v].op == "/") {
        if (y == 0 || (div && x % y != 0)) {
            return -1;
        }
        res = x / y;
    }
    return res;
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
#ifdef DEBUG
    //freopen("/Users/sergiib/Downloads/to_delete/meta3/worklife_balance_chapter_1_input.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s;
    int n = 0;
    while (cin >> s) {
        int v = get_num(s, n);
        string x;
        cin >> x;
        pt now;
        if (x.size() == 4) {
            string op, y;
            cin >> op >> y;
            int from = get_num(x, n);
            int to = get_num(y, n);
            now.x = from;
            now.y = to;
            now.op = op;
        } else {
            now.v = atol(x.c_str());
        }
        g[v] = now;
    }

    int ind = m["humn"];
    pt need = g[ind];
    ll l = 1000000000000;
    ll r = 4000000000000;
    while(!ok) {
        ll mid = (l + r) / 2;
        need.v = mid;
        g[ind] = need;
        go(m["root"], false);
        if (xx < yy) {
            r = mid;
        } else {
            l = mid;
        }
        cerr << mid << "\n";
    }
    xx = -1;
    while(xx == -1) {
        need.v = r;
        g[ind] = need;
        go(m["root"], true);
        --r;
    }
    cout << r + 1;
    return 0;
}
