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
int dy[4] = {1, 0, -1, 0};
//x >= 0 && y >= 0 && x < n && y < m

int n, m;

void add(int &v, int &mx) {
    if (v == 0) {
        v = mx - 2;
    } else if (v == mx - 1) {
        v = 1;
    }
}

void print(vector<VVI> &a, int x, int y) {
    FOR(i, n) {
        FOR(j, m) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                cout << "#";
                continue;
            }
            if (x == i && y == j) {
                cout << "E";
                continue;
            }
            int sum = 0;
            int ind = 0;
            FOR(k, 4) {
                sum += a[i][j][k];
                if (a[i][j][k]) {
                    ind = k;
                }
            }
            if (sum == 0) {
                cout << ".";
            } else if (sum == 1) {
                if (ind == 0) {
                    cout << '>';
                } else if (ind == 1) {
                    cout << 'v';
                } else if (ind == 2) {
                    cout << "<";
                } else {
                    cout << "^";
                }
            } else {
                cout << sum;
            }
        }
        cout << "\n";
    }
    cout << "\n\n";
}

vector<VVI> all[3005];

void pre(vector<VVI> &a) {
    all[0] = a;
    REP(tt, 1, 3005) {
        vector<VVI> b(n, VVI(m, VI(4)));
        REP(i, 1, n - 1) {
            REP(j, 1, m - 1) {
                FOR(k, 4) {
                    if (all[tt - 1][i][j][k] == 0) {
                        continue;
                    }
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    add(nx, n);
                    add(ny, m);
                    b[nx][ny][k] += all[tt - 1][i][j][k];
                }
            }
        }
        all[tt] = b;
    }

    REP(i, 1, n - 1) {
        REP(j, 1, m - 1) {
            FOR(k, 4) {
                if (all[0][i][j][k] != all[3000][i][j][k]) {
                    throw 1;
                }
            }
        }
    }
}

int go(vector<VVI> &a, int from_x, int from_y, int to_x, int to_y, int from) {
    queue<pair<PII, PII>> q;
    q.push(mp(mp(from_x, from_y), mp(0, from + 1)));
    pre(a);
    map<pair<PII, int>, int> cnt;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        int x = v.first.first;
        int y = v.first.second;
        int d = v.second.first;
        int ind = v.second.second % 3000;
        auto key = mp(mp(x, y), ind);
        if (cnt.count(key)) {
            continue;
        }
        cnt[key] = 1;
        //print(a,x,y);
        FOR(k, 4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx == to_x && ny == to_y) {
                return d + 1;
            }
            if (nx >= 1 && nx < n - 1 && ny >= 1 && ny < m - 1) {
                int sum = 0;
                FOR(j, 4) {
                    sum += all[ind][nx][ny][j];
                }
                if (sum == 0) {
                    q.push(mp(mp(nx, ny), mp(d + 1, ind + 1)));
                }
            }
        }
        int sum = 0;
        FOR(j, 4) {
            sum += all[ind][x][y][j];
        }
        if (sum == 0) {
            q.push(mp(mp(x, y), mp(d + 1, ind + 1)));
        }
        //cerr << x << " " << y << "\n";
    }
    return 0;
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
    vector<VVI> a;
    n = 0;
    while (cin >> s) {
        m = s.size();
        VVI now;

        FOR(i, s.size()) {
            VI b(4);
            if (s[i] == '#') {
                //b.pb(-1);
            } else if (s[i] == '.') {
                //b.pb(0);
            } else if (s[i] == '>') {
                //b.pb(1);
                b[0]++;
            } else if (s[i] == 'v') {
                //b.pb(2);
                b[1]++;
            } else if (s[i] == '<') {
                //b.pb(3);
                b[2]++;
            } else if (s[i] == '^') {
                //b.pb(4);
                b[3]++;
            }
            now.pb(b);
        }
        a.pb(now);
        ++n;
    }
    int res1 = go(a, 0, 1, n - 1, m - 2, 0);
    int res2 = go(a, n - 1, m - 2, 0, 1, res1);
    int res3 = go(a, 0, 1, n - 1, m - 2, res1 + res2);
    cout << res1 + res2 + res3;
    return 0;
}