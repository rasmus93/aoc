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

int n;
int m;
VVI g[6];

void print() {
    FOR(i, n) {
        FOR(j, m) {
            int ind;
            if (i < 50) {
                ind = j < 50 ? -1 : (j < 100 ? 1 : 2);
            } else if (i < 100) {
                ind = j >= 50 && j < 100 ? 3 : -1;
            } else if (i < 150) {
                ind = j < 50 ? 4 : (j < 100 ? 5 : -1);
            } else {
                ind = j < 50 ? 6 : -1;
            }
            if (ind == -1) {
                cout << " ";
                continue;
            }
            --ind;

            char c;
            if (g[ind][i % 50][j % 50] == 0) {
                c = '>';
            }
            if (g[ind][i % 50][j % 50] == 1) {
                c = 'v';
            }
            if (g[ind][i % 50][j % 50] == 2) {
                c = '<';
            }
            if (g[ind][i % 50][j % 50] == 3) {
                c = '^';
            }
            if (g[ind][i % 50][j % 50] == 4) {
                c = ' ';
            }
            if (g[ind][i % 50][j % 50] == 5) {
                c = '.';
            }
            if (g[ind][i % 50][j % 50] == 6) {
                c = '#';
            }
            cout << c;
        }
        cout << "\n";
    }
    cout << "\n";
}

VI parse(string &s) {
    VI res;
    string now = "";
    FOR(i, s.size()) {
        if (s[i] == 'R') {
            res.pb(atoi(now.c_str()));
            res.pb(-1);
            now = "";
        } else if (s[i] == 'L') {
            res.pb(atoi(now.c_str()));
            res.pb(-2);
            now = "";
        } else {
            now += s[i];
        }
    }
    res.pb(atoi(now.c_str()));
    return res;
}


int dk[6][4] = {
        {0, 1, 0, 0},
        {2, 2, 2, 3},
        {3, 1, 1, 3},
        {0, 1, 0, 0},
        {2, 2, 2, 3},
        {3, 1, 1, 3}
};

int dind[6][4] = {
        {1, 2, 3, 5},
        {4, 2, 0, 5},
        {1, 4, 3, 0},
        {4, 5, 0, 2},
        {1, 5, 3, 2},
        {4, 1, 0, 3}
};

// ' ' - 4, '.' - 5, '#' - 6
int go(string &s) {
    VI moves = parse(s);
    int k = 0;
    int x = 0;
    int y = 0;
    int ind = 0;
    int n = 50;
    FOR(i, moves.size()) {
        if (moves[i] < 0) {
            if (moves[i] == -1) {
                k = (k + 1 + 4) % 4;
            } else {
                k = (k - 1 + 4) % 4;
            }
            continue;
        }
        //print();
        FOR(j, moves[i]) {
            g[ind][x][y] = k;
            int nx = x + dx[k];
            int ny = y + dy[k];
            //0
            int new_ind = ind;
            int new_k = k;
            if (ny == n) {
                if (ind == 0) {
                    nx = nx;
                    ny = 0;
                }
                if (ind == 1) {
                    nx = n - nx - 1;
                    ny = n - 1;
                }
                if (ind == 2) {
                    ny = nx;
                    nx = n - 1;
                }
                if (ind == 3) {
                    nx = nx;
                    ny = 0;
                }
                if (ind == 4) {
                    nx = n - nx - 1;
                    ny = n - 1;
                }
                if (ind == 5) {
                    ny = nx;
                    nx = n - 1;
                }
                new_ind = dind[ind][k];
                new_k = dk[ind][k];
            }
            //1
            if (nx == n) {
                if (ind == 0) {
                    nx = 0;
                    ny = ny;
                }
                if (ind == 1) {
                    nx = ny;
                    ny = n - 1;
                }
                if (ind == 2) {
                    nx = 0;
                    ny = ny;
                }
                if (ind == 3) {
                    nx = 0;
                    ny = ny;
                }
                if (ind == 4) {
                    nx = ny;
                    ny = n - 1;
                }
                if (ind == 5) {
                    nx = 0;
                    ny = ny;
                }
                new_ind = dind[ind][k];
                new_k = dk[ind][k];
            }
            //2
            if (ny == -1) {
                if (ind == 0) {
                    nx = n - nx - 1;
                    ny = 0;
                }
                if (ind == 1) {
                    nx = nx;
                    ny = n - 1;
                }
                if (ind == 2) {
                    ny = nx;
                    nx = 0;
                }
                if (ind == 3) {
                    nx = n - nx - 1;
                    ny = 0;
                }
                if (ind == 4) {
                    nx = nx;
                    ny = n - 1;
                }
                if (ind == 5) {
                    ny = nx;
                    nx = 0;
                }
                new_ind = dind[ind][k];
                new_k = dk[ind][k];
            }
            //3
            if (nx == -1) {
                if (ind == 0) {
                    nx = ny;
                    ny = 0;
                }
                if (ind == 1) {
                    nx = n - 1;
                    ny = ny;
                }
                if (ind == 2) {
                    nx = n - 1;
                    ny = ny;
                }
                if (ind == 3) {
                    nx = ny;
                    ny = 0;
                }
                if (ind == 4) {
                    nx = n - 1;
                    ny = ny;
                }
                if (ind == 5) {
                    nx = n - 1;
                    ny = ny;
                }
                new_ind = dind[ind][k];
                new_k = dk[ind][k];
            }

            if (g[new_ind][nx][ny] == 6) {
                break;
            }
            ind = new_ind;
            k = new_k;
            x = nx;
            y = ny;
        }
    }

    return 1000 * (x + 100 + 1) + 4 * (y + 1) + g[ind][x][y];
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
    vector<string> z;

    while (getline(cin, s)) {
        if (s == "") {
            break;
        }
        m = max(m, (int) s.size());
        z.pb(s);
    }
    n = z.size();
    cin >> s;
    VVI a(n, VI(m, 4));
    FOR(i,6) {
        g[i] = VVI(50,VI(50));
    }
    FOR(i, n) {
        FOR(j, z[i].size()) {
            if (z[i][j] == ' ') {
                a[i][j] = 4;
            } else {
                int ind;
                if (i < 50) {
                    ind = j < 100 ? 1 : 2;
                } else if (i < 100) {
                    ind = 3;
                } else if (i < 150) {
                    ind = j < 50 ? 4 : 5;
                } else {
                    ind = 6;
                }
                if (z[i][j] == '.') {
                    g[ind - 1][i % 50][j % 50] = 5;
                } else {
                    g[ind - 1][i % 50][j % 50] = 6;
                }
            }
        }
    }

    cout << go(s) << "\n";
    print();
    return 0;
}


//47049 - too low
//65186 - too low
//115186 - too low