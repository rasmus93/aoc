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


const int n = 50000;
const int m = 9;
VVI a(n, VI(m));

void pre() {
    FOR(i, n) {
        a[i][0] = 2;
        a[i][m - 1] = 2;
    }
    FOR(i, m) {
        a[n - 1][i] = 2;
    }
}

string rocks[5][4] = {
        "....",
        "....",
        "....",
        "####",

        "....",
        ".#..",
        "###.",
        ".#..",

        "....",
        "..#.",
        "..#.",
        "###.",

        "#...",
        "#...",
        "#...",
        "#...",

        "....",
        "....",
        "##..",
        "##..",
};

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
    pre();
    string s;
    cin >> s;
    int ind = 0;
    int sz = s.size();
    int rock = 0;

    int x = n - 4 - 4;
    int y = 3;
    int prev = 0;
    VI h;
    while (rock < 20000) {
        /*REP(i, x, n) {
            FOR(j, m) {
                char c = a[i][j] == 2 ? '|' : (a[i][j] == 1 ? '#' : '.');
                cerr << c;
            }
            cerr << "\n";
        }
        cerr << "\n";*/

        VPII b;
        FOR(i, 4) {
            FOR(j, 4) {
                int v = rocks[rock % 5][i][j] == '#' ? 1 : 0;
                //a[x + i][y + j] = v;
                if (v == 1) {
                    b.pb(mp(x + i, y + j));
                }
            }
        }
        while (true) {
            char c = s[ind % sz];
            ++ind;

            // left or right
            int add = 0;
            if (c == '>') {
                add = 1;
            } else {
                add = -1;
            }
            bool ok1 = true;
            FOR(i, b.size()) {
                if (a[b[i].first][b[i].second + add]) {
                    ok1 = false;
                    break;
                }
            }
            if (ok1) {
                FOR(i, b.size()) {
                    b[i].second += add;
                }
            }


            // down
            bool ok2 = true;
            FOR(i, b.size()) {
                if (a[b[i].first + 1][b[i].second]) {
                    ok2 = false;
                    break;
                }
            }
            if (ok2) {
                FOR(i, b.size()) {
                    b[i].first++;
                }
            }
            if (!ok2) {
                break;
            }
        }
        FOR(i, b.size()) {
            a[b[i].first][b[i].second] = 1;
        }

        bool found = false;
        REP(i, x, n) {
            REP(j, 1, m - 1) {
                if (a[i][j] == 1) {
                    x = i;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        y = 3;
        x -= 7;
        ++rock;

        int gg = -1;
        REP(i, x, n) {
            REP(j, 1, m - 1) {
                if (a[i][j] == 1) {
                    gg = i;
                    break;
                }
            }
            if (gg != -1) {
                break;
            }
        }
        //cerr << (n - 1) - gg << "\n";
        gg = (n - 1) - gg;
        h.pb(gg - prev);
        cerr << gg - prev << "\n";
        prev = gg;
    }

    int hh = h.size();
    int start = -1;
    int end = -1;
    int check_period_size = 30;
    FOR(i, hh - check_period_size) {
        REP(k, i + check_period_size, hh) {
            bool ok = true;
            FOR(j,check_period_size) {
                if (h[i + j] != h[k + j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                start = i;
                end = k;
                break;
            }
        }
        if (start != -1) {
            break;
        }
    }

    ll res = 0;
    FOR(i,start) {
        res += h[i];
    }
    cout << res << "\n";
    ll sum = 0;
    REP(i,start,end) {
        sum += h[i];
    }
    cout << sum << " " << end - start << "\n";
    ll need_rocks = 1000000000000ll;
    res += (need_rocks - start) / (end - start) * sum;
    ll left = (need_rocks - start) % (end - start);
    REP(i,start, start + left) {
        res += h[i];
    }
    cout << res << "\n";
    return 0;
}

