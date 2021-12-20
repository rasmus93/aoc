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

string scan(stringstream &ss, char delim) {
    string v;
    getline(ss, v, delim);
    return v;
}

int scan_int(stringstream &ss, char delim) {
    return atoi(scan(ss, delim).c_str());
}

vector<string> scan_strings(stringstream &ss, char delim) {
    string v;
    vector<string> res;
    while (getline(ss, v, delim)) {
        res.pb(v);
    }
    return res;
}

vector<ll> scan_longs(stringstream &ss, char delim) {
    string v;
    vector<ll> res;
    while (getline(ss, v, delim)) {
        res.pb(atol(v.c_str()));
    }
    return res;
}

VI scan_ints(stringstream &ss, char delim) {
    string v;
    VI res;
    while (getline(ss, v, delim)) {
        res.pb(atoi(v.c_str()));
    }
    return res;
}

const int N = 1000;
int a[N + 5][N + 5];
int b[N + 5][N + 5];

//116305
int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s;
    cin >> s;
    string z;

    int cnt = N / 2;
    while (cin >> z) {
        FOR(i, z.size()) {
            a[cnt][i + N / 2] += z[i] == '#' ? 1 : 0;
        }
        ++cnt;
    }

    FOR(tt, 50) {
        REP(i, 1 + tt, N - tt) {
            REPE(j, 1 + tt , N - tt) {
                int res = 0;
                REPE(x, -1, 1) {
                    REPE(y, -1, 1) {
                        res <<= 1;
                        res += a[i + x][j + y];
                    }
                }
                /*if (res != 0) {
                    cout << res << "\n";
                }*/
                b[i][j] = s[res] == '#' ? 1 : 0;
            }
        }
        swap(a, b);
        /*REP(i, 1, N) {
            REPE(j, 1, N) {
                cout << (a[i][j] == 1 ? "#" : ".");
            }
            cout << "\n";
        }
        cout << "\n\n\n";*/
        cerr << tt << "\n";
    }

    int res = 0;
    REP(i, 2 + 50, N - 1 - 50) {
        REPE(j, 2 + 50, N - 1 - 50) {
            res += a[i][j];
        }
    }
    REP(i, 1, N) {
            REPE(j, 1, N) {
                cout << (a[i][j] == 1 ? "#" : ".");
            }
            cout << "\n";
        }
        cout << "\n\n\n";
    cout << res;
    return 0;
}
