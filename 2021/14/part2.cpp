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

vector<ll> scan_ints(stringstream &ss, char delim) {
    string v;
    vector<ll> res;
    while (getline(ss, v, delim)) {
        res.pb(atol(v.c_str()));
    }
    return res;
}


int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<ll>> a(26, vector<ll>(26));
    PII first;
    PII last;
    first = mp(s[0] - 'A', s[1] - 'A');
    last = mp(s[n - 2] - 'A', s[n - 1] - 'A');
    REP(i, 1, n) {
        int x = s[i - 1] - 'A';
        int y = s[i] - 'A';
        a[x][y]++;
    }
    string from, z, to;
    vector<char> x;
    vector<char> y;
    vector<char> c;
    while (cin >> from >> z >> to) {
        char xx = from[0];
        char yy = from[1];
        char cc = to[0];
        x.pb(xx);
        y.pb(yy);
        c.pb(cc);
    }
    int m = x.size();
    FOR(tt, 40) {
        vector<vector<ll>> b(26, vector<ll>(26));
        FOR(i, 26) {
            FOR(j, 26) {
                if (a[i][j] == 0) {
                    continue;
                }
                FOR(k, m) {
                    int xx = x[k] - 'A';
                    int yy = y[k] - 'A';
                    int cc = c[k] - 'A';
                    if (i == xx && j == yy) {
                        b[xx][cc] += a[i][j];
                        b[cc][yy] += a[i][j];
                        if (first.first == i && first.second == j) {
                            first.second = cc;
                        }
                        if (last.first == i && last.second == j) {
                            last.first = cc;
                        }
                        break;
                    }
                }
            }
        }
        /*FOR(i, 26) {
            FOR(j, 26) {
                if (b[i][j] != 0) {
                    cerr << (char) (i + 'A') << (char) (j + 'A') << " " << b[i][j] << "\n";
                }
            }
        }*/
        swap(a, b);
        cerr << tt << "\n";
    }

    vector<ll> cnt(26);
    FOR(i, 26) {
        FOR(j, 26) {
            if (a[i][j] != 0) {
                cnt[i] += a[i][j];
                cnt[j] += a[i][j];
            }
        }
    }
    cnt[first.first] += 1;
    cnt[last.second] += 1;
    ll mx = -1;
    ll mn = (ll) 1e18;
    FOR(i, 26) {
        mx = max(cnt[i] / 2, mx);
        if (cnt[i] != 0) {
            cerr << (char) (i + 'A') << " " << cnt[i] / 2 << "\n";
            mn = min(cnt[i] / 2, mn);
        }
    }
    cout << mx - mn;
    return 0;
}
