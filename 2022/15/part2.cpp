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
    int mn = 0;
    int mx = 4000000;
    //int mx = 20;
    map<int, VPII> m;
    map<PII, int> b;
    while (cin >> s >> s) {
        int sx, sy;
        cin >> sy >> sx;
        cin >> s >> s >> s >> s;
        int bx, by;
        cin >> by >> bx;
        b[mp(bx, by)] = 1;
        int diff = abs(bx - sx) + abs(by - sy);
        int lx = sx - diff;
        int rx = sx + diff;
        if (lx < mn && rx < mn || lx > mx && rx > mx) {
            continue;
        }
        lx = max(lx, mn);
        lx = min(lx, mx);
        rx = max(rx, mn);
        rx = min(rx, mx);
        REPE(i, lx, rx) {
            int minus = abs(i - sx);
            minus = diff - minus;
            int ly = sy - minus;
            int ry = sy + minus;
            if (ly < mn && ry < mn || ly > mx && ry > mx) {
                continue;
            }
            ly = max(ly, mn);
            ly = min(ly, mx);
            ry = max(ry, mn);
            ry = min(ry, mx);
            m[i].pb(mp(ly, ry));
        }
    }
    int resx = -1;
    int resy = -1;
    REPE(i, mn, mx) {
        VPII now = m[i];
        sort(now.begin(), now.end());
        int l = 0;
        for (auto v: now) {
            if (v.first - l > 1) {
                resx = i;
                resy = l + 1;
                break;
            }
            l = max(v.second,l);
        }
        if (resx != -1) {
            break;
        }
    }
    cout << resy * 1ll * 4000000 + resx;
    return 0;
}