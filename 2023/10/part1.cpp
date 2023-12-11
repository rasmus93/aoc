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

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool check(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool pred(const pair<string, ll> &i, const pair<string, ll> &j) {
    return false;
}

string z = "F7JL|-.S";
vector<vector<int>> a;
int n, m;

vector<PII> moves;

void pre() {
    moves.pb(mp(2, 3));
    moves.pb(mp(0, 3));
    moves.pb(mp(0, 1));
    moves.pb(mp(2, 1));
    moves.pb(mp(1, 3));
    moves.pb(mp(0, 2));
}

int go(int x, int y) {
    queue<PII> q;
    q.push(mp(x, y));
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    cnt[x][y] = 1;
    while (!q.empty()) {
        PII v = q.front();
        q.pop();
        x = v.first;
        y = v.second;
        if (cnt[x][y] == 7) {
            int gg = 1;
        }
        int ind = a[x][y];
        int nx = x + dx[moves[ind].first];
        int ny = y + dy[moves[ind].first];
        if (check(nx, ny, n, m) && cnt[nx][ny] == 0) {
            cnt[nx][ny] = cnt[x][y] + 1;
            q.push(mp(nx, ny));
        }
        nx = x + dx[moves[ind].second];
        ny = y + dy[moves[ind].second];
        if (check(nx, ny, n, m) && cnt[nx][ny] == 0) {
            cnt[nx][ny] = cnt[x][y] + 1;
            q.push(mp(nx, ny));
        }
    }
    int res = 0;
    FOR(i,n) {
        FOR(j,m) {
            //cout << cnt[i][j];
            res = max(res,cnt[i][j]);
        }
        //cout << "\n";
    }
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

    int x, y;
    n = 0;
    while (cin >> s) {
        vector<int> now;
        FOR(i, s.size()) {
            FOR(j, z.size()) {
                if (s[i] == z[j]) {
                    if (z[j] == 'S') {
                        x = n;
                        y = i;
                    }
                    now.pb(j);
                    break;
                }
            }
        }
        a.pb(now);
        ++n;
    }
    n = a.size();
    m = a[0].size();
    // fix
    if (n > 20) {
        a[x][y] = 4;
    } else {
        a[x][y] = 0;
    }
    pre();
    cout << go(x, y) - 1;
    return 0;
}
