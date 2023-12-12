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

// # - 0
// . - 1
ll solve(string s, vector<ll> a) {
    int n = s.size();
    int to = 1 << n;

    int res = 0;
    FOR(i, to) {
        vector<int> now;
        int v = i;
        while (v) {
            now.pb(v % 2);
            v /= 2;
        }
        while (now.size() != n) {
            now.pb(0);
        }
        reverse(now.begin(), now.end());
        vector<int> cnt;
        int k = 0;
        int spring = 0;
        while (k < n) {
            while(k < n && now[k] == 1) {
                ++spring;
                ++k;
            }
            if (spring) {
                cnt.pb(spring);
                spring = 0;
            } else {
                ++k;
            }
        }
        if (spring) {
            cnt.pb(spring);
        }
        if (cnt.size() != a.size()) {
            continue;
        }
        bool ok = true;
        FOR(j,a.size()) {
            if (cnt[j] != a[j]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        FOR(j, n) {
            if (s[j] == '?') {
                continue;
            } else if (s[j] == '#') {
                if (now[j] != 1) {
                    ok = false;
                    break;
                }
            } else {
                if (now[j] != 0) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            ++res;
        }
    }
    cerr << res << "\n";
    return res;
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
    string x;
    ll res = 0;
    int n = 0;
    while (cin >> s >> x) {
        vector<ll> a = scan_lls(x, ',');
        res += solve(s, a);
        //cerr << n << "\n";
        ++n;
    }
    cout << res;
    return 0;
}
