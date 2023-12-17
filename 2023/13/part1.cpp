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
typedef vector<ll> VI;
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

ll solve(vector<string> &a) {
    if (a.empty()) {
        return 0;
    }
    int n = a.size();
    int m = a[0].size();
    FOR(i, n - 1) {
        int x = i;
        int y = i + 1;
        bool ok = true;
        while (x >= 0 && y < n) {
            if (a[x] != a[y]) {
                ok = false;
                break;
            }
            --x;
            ++y;
        }
        if (ok) {
            return (i + 1) * 100;
        }
    }
    FOR(j, m - 1) {
        int x = j;
        int y = j + 1;
        bool ok = true;
        while(x >= 0 && y < m) {
            FOR(i,n) {
                if (a[i][x] != a[i][y]) {
                    ok = false;
                    break;
                }
            }
            --x;
            ++y;
        }
        if (ok) {
            return j + 1;
        }
    }
    return 0;
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
    vector<string> a;
    ll res = 0;
    while (getline(cin, s)) {
        if (s.empty()) {
            int now = solve(a);
            cerr << now << "\n";
            res += now;
            a.clear();
            continue;
        }
        a.pb(s);
    }
    int now = solve(a);
    cerr << now << "\n";
    res += now;
    cout << res;
    return 0;
}
