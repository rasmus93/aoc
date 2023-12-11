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

int a[500][500];
int b[500][500];
int c[500][500];

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
    int n = 0;
    int m;
    while (cin >> s) {
        m = s.size();
        FOR(i, m) {
            if (s[i] == '.') {
                a[n][i] = 0;
            } else {
                a[n][i] = 1;
            }
        }
        ++n;
    }

    int bn = 0;
    int bm = m;
    FOR(i, n) {
        bool need = true;
        FOR(j, m) {
            if (a[i][j] == 1) {
                need = false;
            }
            b[bn][j] = a[i][j];
        }
        ++bn;
        if (need) {
            FOR(j, m) {
                b[bn][j] = a[i][j];
            }
            ++bn;
        }
    }
    for (int j = bm - 1; j > 0; --j) {
        bool need = true;
        FOR(i, bn) {
            if (b[i][j] == 1) {
                need = false;
            }
        }

        if (need) {
            FOR(ii, bn) {
                for (int jj = bm; jj > j; --jj) {
                    b[ii][jj] = b[ii][jj - 1];
                }
            }
            FOR(i, bn) {
                b[i][j] = 0;
            }
            ++bm;
        }
    }
    /*FOR(i,bn) {
        FOR(j,bm) {
            cout << b[i][j];
        }
        cout << "\n";
    }*/
    vector<PII> stars;
    FOR(i, bn) {
        FOR(j, bm) {
            if (b[i][j] == 1) {
                stars.pb(mp(i, j));
            }
        }
    }
    ll res = 0;
    FOR(i, stars.size()) {
        REP(j, i + 1, stars.size()) {
            res += abs(stars[i].first - stars[j].first);
            res += abs(stars[i].second - stars[j].second);
        }
    }
    cout << res;
    return 0;
}
