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

const int N = 100;

VI g[N];
bool big[N];
map<string, int> m;

int cnt = 0;
int res = 0;
int start;
int finish;

void go(int v, VB used, bool twice) {
    if (v == finish) {
        ++res;
        return;
    }
    if (!big[v]) {
        used[v] = true;
    }
    FOR(i, g[v].size()) {
        int to = g[v][i];
        if (to == start) {
            continue;
        }
        if (!used[to]) {
            go(to, used, twice);
        } else if (!twice && !big[to]) {
            go(to, used, true);
        }
    }
}

int get_index(string s) {
    int v;
    if (m.count(s) == 0) {
        v = cnt++;
        m[s] = v;
    } else {
        v = m[s];
    }
    if (s[0] >= 'A' && s[0] <= 'Z') {
        big[v] = true;
    }

    return v;
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    string s;
    while (cin >> s) {
        stringstream ss(s);
        string from,to;
        getline(ss, from, '-');
        getline(ss, to, '-');
        int x = get_index(from);
        int y = get_index(to);
        g[x].pb(y);
        g[y].pb(x);
    }

    start = m["start"];
    finish = m["end"];
    VB used(cnt);
    go(start, used, false);
    cout << res;
    return 0;
}
