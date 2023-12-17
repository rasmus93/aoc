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

const int inf = (int) 1e9;

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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool pred(const pair<string, ll> &i, const pair<string, ll> &j) {
    return false;
}

int n, m;

struct pt {
    int x;
    int y;
    int from;
    int cnt;
};

int solve(VVI &a) {
    queue<pt> q;
    q.push(pt{0, 0, -1, 0});
    map<pair<PII, PII>, int> best;
    best[mp(mp(0, 0), mp(-1, 0))] = 0;
    int res = inf;
    while (!q.empty()) {
        pt v = q.front();
        q.pop();
        pair<PII, PII> vv = mp(mp(v.x, v.y), mp(v.from, v.cnt));
        if (v.x == n - 1 && v.y == m - 1) {
            res = min(res, best[vv]);
            continue;
        }
        FOR(k, 4) {
            if (abs(v.from - k) == 2 && v.from != -1) {
                continue;
            }
            if (v.cnt == 10 && v.from == k) {
                continue;
            }
            if (v.cnt < 4 && v.from != k && v.from != -1) {
                continue;
            }
            int x = v.x + dx[k];
            int y = v.y + dy[k];
            if (check(x, y, n, m)) {
                int cnt = v.from == k ? v.cnt + 1 : 1;
                pair<PII, PII> next = mp(mp(x, y), mp(k, cnt));
                int next_res = best[vv] + a[x][y];
                if (best.count(next) == 0 || best[next] > next_res) {
                    if (next_res >= res) {
                        continue;
                    }
                    best[next] = next_res;
                    q.push(pt{x, y, k, cnt});
                }
            }
        }
    }
    /*VVI cnt(n, VI(m, inf));
    for (auto v: best) {
        cnt[v.first.first.first][v.first.first.second] = min(cnt[v.first.first.first][v.first.first.second], v.second);
    }
    FOR(i, n) {
        FOR(j, m) {
            cout << cnt[i][j] << " ";
        }
        cout << "\n";
    }*/
    return res;
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
    VVI a;
    while (cin >> s) {
        VI now;
        FOR(i, s.size()) {
            now.pb(s[i] - '0');
        }
        a.pb(now);
    }
    n = a.size();
    m = a[0].size();
    cout << solve(a);
    return 0;
}
