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

VI g[100];
int cnt = 0;
VB big(100);
map<string, int> m;
map<int, string> xz;
int finish;
int start;
int res = 0;

vector<string> ss;

void go(int v, VB used, VI path, bool twice) {
    if (v == finish) {
        ++res;
        string now = "start";
        FOR(i,path.size()) {
            //cout << xz[path[i]] << ",";
            now += "," +  xz[path[i]];
        }
        ss.pb(now);
        return;
    }
    FOR(i, g[v].size()) {
        int to = g[v][i];
        if (to == start) {
            continue;
        }
        if (!used[to]) {
            if (!big[to]) {
                used[to] = true;
            }
            path.pb(to);
            go(to, used, path, twice);
            path.pop_back();
            used[to] = false;
        } else if (!twice && !big[to]) {
            path.pb(to);
            go(to, used, path, true);
            path.pop_back();
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
    string from, to;
    while (cin >> from >> to) {
        int x;
        if (m.count(from) == 0) {
            x = cnt++;
            m[from] = x;
        } else {
            x = m[from];
        }
        int y;
        if (m.count(to) == 0) {
            y = cnt++;
            m[to] = y;
        } else {
            y = m[to];
        }
        if (from[0] >= 'A' && from[0] <= 'Z') {
            big[x] = true;
        }
        if (to[0] >= 'A' && to[0] <= 'Z') {
            big[y] = true;
        }
        xz[x] = from;
        xz[y] = to;
        g[x].pb(y);
        g[y].pb(x);
    }

    finish = m["end"];
    start = m["start"];
    VB used(cnt);
    VI path;
    go(m["start"], used, path, false);
    cout << res;

    /*sort(ss.begin(), ss.end());
    FOR(i,ss.size()) {
        cout << ss[i] << "\n";
    }*/
    return 0;
}
