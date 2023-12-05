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
typedef pair<ll, ll> PII;
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

vector<string> scan_strings(stringstream &ss, char delim) {
    string v;
    vector<string> res;
    while (getline(ss, v, delim)) {
        res.pb(v);
    }
    return res;
}

VI g[1005];

string get_path(vector<string> &s) {
    string res = "";
    FOR(i, s.size()) {
        res += s[i];
    }
    return res;
}

int get_next_ind_and_add(vector<string> &now, map<string, int> &dirs, int &cnt, int &ind) {
    string path = get_path(now);
    int next_ind;
    if (dirs.count(path) == 0) {
        next_ind = cnt;
        dirs[path] = cnt;
        cnt++;
        g[ind].pb(next_ind);
    } else {
        next_ind = dirs[path];
    }
    return next_ind;
}

map<int, ll> sizes;
ll sum = 0;

int calc(int v) {
    ll res = sizes[v];
    FOR(i,g[v].size()) {
        int to = g[v][i];
        res += calc(to);
    }
    if (res <= 100000) {
        sum += res;
    }
    return res;
}

ll mn = inf;

int calc2(int v, int &need) {
    ll res = sizes[v];
    FOR(i,g[v].size()) {
        int to = g[v][i];
        res += calc2(to,need);
    }
    if (res >= need) {
        mn = min(res,mn);
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
    cin >> s >> s >> s;
    map<string, int> dirs;
    dirs["/"] = 0;
    sizes[0] = 0;
    int cnt = 1;
    vector<string> now;
    now.pb("/");
    int ind = 0;
    string command;
    while (cin >> s) {
        if (s == "$") {
            cin >> command;
        }
        if (command == "cd") {
            string where;
            cin >> where;
            if (where == "..") {
                now.pop_back();
                continue;
            }
            if (where == "/") {
                now.clear();
                now.pb("/");
                continue;
            }
            now.pb(where);
            int next_ind = get_next_ind_and_add(now, dirs, cnt, ind);
            ind = next_ind;

            continue;
        }
        if (command == "ls") {
            string x, y;
            if (s == "$") {
                cin >> x >> y;
            } else {
                x = s;
                cin >> y;
            }

            if (x == "dir") {
                now.push_back(y);
                get_next_ind_and_add(now, dirs, cnt, ind);
                now.pop_back();
            } else {
                string path = get_path(now);
                ll sz = atol(x.c_str());
                int next_ind = get_next_ind_and_add(now, dirs, cnt, ind);
                sizes[next_ind] += sz;
            }
        }
    }
    ll total = calc(0);
    int free = 70000000 - total;
    int need = 30000000 - free;
    calc2(0,need);
    cout << mn;
    return 0;
}