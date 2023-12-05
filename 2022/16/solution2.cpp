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

VI g[150];
VPII g2[150];
VI d(150);

//v,used,left -> res
map<tuple<int, int, int>, int> xz;
map<int,int> old_ind;

int go(int v, int used = 0, int left = 30) {
    tuple<int, int, int> key = tuple(v, used, left);
    if (xz.count(key)) {
        return xz[key];
    }

    int res = 0;
    FOR(i, g2[v].size()) {
        int to = g2[v][i].first;
        if ((used & (1 << to))) {
            continue;
        }
        int next_left = left - g2[v][i].second - 1;
        if (next_left <= 0) {
            continue;
        }
        res = max(
                res,
                go(to, used | (1 << to), next_left) + d[old_ind[to]] * next_left
        );
    }
    xz[key] = res;
    return res;
}

VVI pre(int n, VI &flows) {
    VVI dp(n, VI(n, inf));
    FOR(i, n) {
        FOR(j, g[i].size()) {
            dp[i][g[i][j]] = 1;
        }
    }
    FOR(i, n) {
        dp[i][i] = 0;
    }
    FOR(k, n) {
        FOR(i, n) {
            FOR(j, n) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    FOR(i, flows.size()) {
        FOR(j, flows.size()) {
            if (i == j) {
                continue;
            }
            g2[i].pb(mp(j, dp[flows[i]][flows[j]]));
        }
    }

    FOR(i,flows.size()) {
        old_ind[i] = flows[i];
    }
    return dp;
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
    string from;
    map<string, int> m;
    int n = 0;
    VI flows;
    while (cin >> s) {
        cin >> from;
        if (m.count(from) == 0) {
            m[from] = n++;
        }
        int flow;
        cin >> s >> s >> flow;
        d[m[from]] = flow;
        if (flow > 0) {
            flows.pb(m[from]);
        }
        string to;
        cin.get();
        getline(cin, to);
        stringstream ss(to);
        vector<string> values = scan_strings(ss, ' ');
        FOR(i, values.size()) {
            if (m.count(values[i]) == 0) {
                m[values[i]] = n++;
            }
            g[m[from]].pb(m[values[i]]);
        }
    }
    flows.pb(m["AA"]);
    pre(n, flows);
    cout << go(flows.size() - 1, 0, 30) << "\n";

    int all = (1 << (flows.size())) - 1;
    int res2 = 0;
    FOR(i, all / 2 + 1) {
        if (i % 1000 == 0) {
            cerr << i << "\n";
        }
        int me = i;
        int elephant = i ^ all;
        res2 = max(
                res2,
                go(flows.size() - 1, me, 26)
                + go(flows.size() - 1, elephant, 26)
        );
    }
    cout << res2;
    return 0;
}
