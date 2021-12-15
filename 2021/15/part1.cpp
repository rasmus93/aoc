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

int a[2005][2005];
bool used[2005][2005];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int n = 0;
int m;

void go(VVI &dp, int i, int j) {
    FOR(k, 4) {
        int x = dx[k] + i;
        int y = dy[k] + j;
        if (x >= 0 && y >= 0 && x < n && y < m && dp[x][y] > dp[i][j] + a[x][y]) {
            dp[x][y] = dp[i][j] + a[x][y];
            go(dp, x, y);
        }
    }
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s;

    while (cin >> s) {
        FOR(i, s.size()) {
            a[n][i] = s[i] - '0';
        }
        ++n;
    }
    m = s.size();
    VVI dp(n, VI(m, (int) (1e9)));

    dp[0][0] = 0;
    go(dp, 0, 0);
    FOR(i, n) {
        FOR(j, m) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << dp[n - 1][m - 1];
    return 0;
}
