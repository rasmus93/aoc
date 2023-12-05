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
//VI values = scan_ints(ss, ',');
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


int tox, toy;

int go(VVI &a, int fromx, int fromy) {
    queue<PII> q;
    q.push(mp(fromx, fromy));
    int n = a.size();
    int m = a[0].size();
    VVI dp(n, VI(m, inf));
    dp[fromx][fromy] = 0;
    while (!q.empty()) {
        PII v = q.front();
        q.pop();
        FOR(k, 4) {
            int x = v.first + dx[k];
            int y = v.second + dy[k];
            if (x >= 0 && y >= 0 && x < n && y < m
                && a[x][y] <= a[v.first][v.second] + 1 && dp[x][y] == inf) {
                dp[x][y] = dp[v.first][v.second] + 1;
                q.push(mp(x,y));
            }
        }
    }
    return dp[tox][toy];
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
    VVI a;
    VI fromx;
    VI fromy;
    int n = 0;
    while (cin >> s) {
        VI now(s.size());
        FOR(i, s.size()) {
            if (s[i] == 'S') {
                fromx.pb(n);
                fromy.pb(i);
                now[i] = 0;
                continue;
            }
            if (s[i] == 'E') {
                tox = n;
                toy = i;
                now[i] = 25;
                continue;
            }
            now[i] = s[i] - 'a';
            if (s[i] == 'a') {
                fromx.pb(n);
                fromy.pb(i);
            }
        }
        a.pb(now);
        ++n;
    }
    int res = inf;
    FOR(i,fromx.size()) {
        res = min(res,go(a,fromx[i], fromy[i]));
    }
    cout << res;
    return 0;
}