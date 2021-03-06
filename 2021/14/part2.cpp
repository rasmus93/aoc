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
        x.pb(from[0]);
        y.pb(from[1]);
        c.pb(to[0]);
    }
    int m = x.size();
    FOR(tt, 40) {
        vector<vector<ll>> b(26, vector<ll>(26));
        FOR(k, m) {
            int xx = x[k] - 'A';
            int yy = y[k] - 'A';
            int cc = c[k] - 'A';
            b[xx][cc] += a[xx][yy];
            b[cc][yy] += a[xx][yy];
        }
        swap(a, b);
        cerr << tt << "\n";
    }

    vector<ll> cnt(26);
    FOR(i, 26) {
        FOR(j, 26) {
            cnt[i] += a[i][j];
            cnt[j] += a[i][j];
        }
    }
    cnt[s[0] - 'A'] += 1;
    cnt[s[n - 1] - 'A'] += 1;
    ll mx = -1;
    ll mn = (ll) 1e18;
    FOR(i, 26) {
        cnt[i] /= 2;
        mx = max(cnt[i], mx);
        if (cnt[i] != 0) {
            cerr << (char) (i + 'A') << " " << cnt[i] << "\n";
            mn = min(cnt[i], mn);
        }
    }
    cout << mx - mn;
    return 0;
}
