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

int box(string &s) {
    ll res = 0;
    FOR(j, s.size()) {
        res += s[j];
        res *= 17;
        res %= 256;
    }
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
    getline(cin, s);

    vector<string> a = scan_strings(s, ',');
    vector<vector<pair<string, int>>> boxes(256);
    FOR(i, 256) {
        vector<pair<string, int>> now;
        boxes.pb(now);
    }
    FOR(i, a.size()) {
        if (a[i].back() != '-') {
            vector<string> v = scan_strings(a[i], '=');
            int now = box(v[0]);
            bool exist = false;
            FOR(j, boxes[now].size()) {
                if (boxes[now][j].first == v[0]) {
                    exist = true;
                    boxes[now][j].second = atoi(v[1].c_str());
                    break;
                }
            }
            if (!exist) {
                boxes[now].pb(mp(v[0], atoi(v[1].c_str())));
            }
            //cerr << box(v[0]) << "\n";
        } else {
            string v = a[i].substr(0, a[i].size() - 1);
            int now = box(v);
            int ind = -1;
            vector<pair<string, int>> next;
            FOR(j, boxes[now].size()) {
                if (boxes[now][j].first == v) {
                    continue;
                }
                next.pb(boxes[now][j]);
            }
            boxes[now] = next;
            //cerr << v << " " << box(v) << "\n";
        }
    }
    ll res = 0;
    FOR(i, 256) {
        FOR(j, boxes[i].size()) {
            res += (i + 1) * 1ll * (j + 1) * boxes[i][j].second;
        }
    }
    cout << res;
    return 0;
}
