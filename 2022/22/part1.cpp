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

void print(VVI &a) {
    FOR(i, n) {
        FOR(j, m) {
            char c;
            if (a[i][j] == 0) {
                c = '>';
            }
            if (a[i][j] == 1) {
                c = 'v';
            }
            if (a[i][j] == 2) {
                c = '<';
            }
            if (a[i][j] == 3) {
                c = '^';
            }
            if (a[i][j] == 4) {
                c = ' ';
            }
            if (a[i][j] == 5) {
                c = '.';
            }
            if (a[i][j] == 6) {
                c = '#';
            }
            cout << c;
        }
        cout << "\n";
    }
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


// ' ' - 4, '.' - 5, '#' - 6
int go(VVI &a, int x, int y, string &s) {
    VI moves = parse(s);
    int k = 0;
    FOR(i, moves.size()) {
        if (moves[i] < 0) {
            if (moves[i] == -1) {
                k = (k + 1 + 4) % 4;
            } else {
                k = (k - 1 + 4) % 4;
            }
            continue;
        }
        FOR(j, moves[i]) {
            a[x][y] = k;
            int nx = (x + dx[k] + n) % n;
            int ny = (y + dy[k] + m) % m;
            while(a[nx][ny] == 4) {
                nx = (nx + dx[k] + n) % n;
                ny = (ny + dy[k] + m) % m;
            }
            if (a[nx][ny] == 6) {
                break;
            }
            x = nx;
            y = ny;
        }
    }

    return 1000 * (x + 1) + 4 * (y + 1) + a[x][y];
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
    FOR(i, n) {
        FOR(j, z[i].size()) {
            if (z[i][j] == ' ') {
                a[i][j] = 4;
            } else if (z[i][j] == '.') {
                a[i][j] = 5;
            } else {
                a[i][j] = 6;
            }
        }
    }

    int x = 0;
    int y = 0;
    FOR(j, m) {
        if (a[0][j] == 5) {
            y = j;
            break;
        }
    }
    cout << go(a, x, y, s);
    return 0;
}
