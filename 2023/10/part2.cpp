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

void go(VVI &cnt, int x, int y) {
    int ind = a[x][y];
    int nx = x + dx[moves[ind].first];
    int ny = y + dy[moves[ind].first];
    if (check(nx, ny, n, m) && cnt[nx][ny] == 0) {
        cnt[nx][ny] = cnt[x][y] + 1;
        go(cnt, nx, ny);
    }
    nx = x + dx[moves[ind].second];
    ny = y + dy[moves[ind].second];
    if (check(nx, ny, n, m) && cnt[nx][ny] == 0) {
        cnt[nx][ny] = cnt[x][y] + 1;
        go(cnt, nx, ny);
    }
}

int mx = 0;

int go3(VVI &cnt, int x, int y, int k) {
    int nx = x + dx[k];
    int ny = y + dy[k];
    if (x == 9 && y == 0) {
        int gg = 1;
    }
    int intersect = 0;
    while (check(nx, ny, n, m)) {
        int need = 0;
        int step = 0;
        bool up = false;
        if (cnt[nx][ny]
            && (abs(cnt[nx][ny] - cnt[nx + 1][ny]) == 1
                || cnt[nx][ny] == 10 && cnt[nx + 1][ny] == mx
                || cnt[nx][ny] == mx && cnt[nx + 1][ny] == 10)) {
            up = true;
        }
        while (check(nx, ny, n, m) && cnt[nx][ny]) {
            ++need;
            if (abs(cnt[nx][ny] - cnt[nx + dx[k]][ny + dy[k]]) != 1
                && !(cnt[nx][ny] == 10 && cnt[nx + dx[k]][ny + dy[k]] == mx
                    || cnt[nx][ny] == mx && cnt[nx + dx[k]][ny + dy[k]] == 10)) {
                break;
            }
            nx += dx[k];
            ny += dy[k];
            ++step;
        }
        if (need == 1) {
            ++intersect;
        } else {
            if (need) {
                if (up) {
                    ++intersect;
                }
                if (cnt[nx][ny]
                    && (abs(cnt[nx][ny] - cnt[nx + 1][ny]) == 1
                        || cnt[nx][ny] == 10 && cnt[nx + 1][ny] == mx
                        || cnt[nx][ny] == mx && cnt[nx + 1][ny] == 10)) {
                    ++intersect;
                }
            }
        }
        nx += dx[k];
        ny += dy[k];
    }
    return intersect;
}

int go2(int x, int y) {
    vector<vector<int>> cnt(n, vector<int>(m, 0));
    cnt[x][y] = 10;
    go(cnt, x, y);
    FOR(i, n) {
        FOR(j, m) {
            mx = max(mx, cnt[i][j]);
        }
    }
    cout << "\n";
    int res = 0;
    FOR(i, n) {
        FOR(j, m) {
            if (cnt[i][j] != 0) {
                cout << "O";
                continue;
            }

            if (go3(cnt, i, j, 2) % 2 == 1) {
                cout << "I";
                ++res;
            } else {
                cout << ".";
            }
        }
        cout << "\n";
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
    VI border;
    while (cin >> s) {
        s = "." + s + ".";
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
        if (a.empty()) {
            FOR(i, s.size()) {
                border.pb(6);
            }
            a.pb(border);
        }
        a.pb(now);
        ++n;
    }
    a.pb(border);
    ++x;
    n = a.size();
    m = a[0].size();
    // fix
    if (n > 20) {
        a[x][y] = 4;
    } else {
        a[x][y] = 1;
    }
    pre();
    cout << go2(x, y);
    return 0;
}
