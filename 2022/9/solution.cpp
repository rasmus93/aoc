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
typedef pair<ll, ll> PII;
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
//VI values = scan_ints(ss, ',');
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
    int v;
    int n = 2;
    VI x(n);
    VI y(n);
    FOR(i, n) {
        x[i] = 100000;
        y[i] = 100000;
    }
    map<PII, int> m;
    m[mp(x[n - 1], y[n - 1])]++;
    while (cin >> s >> v) {
        int ind = 0;
        if (s == "U") {
            ind = 0;
        } else if (s == "R") {
            ind = 1;
        } else if (s == "D") {
            ind = 2;
        } else if (s == "L") {
            ind = 3;
        }
        FOR(i, v) {
            x[0] += dx[ind];
            y[0] += dy[ind];
            REP(j, 1, n) {
                int ax = abs(x[j - 1] - x[j]);
                int ay = abs(y[j - 1] - y[j]);
                if (ax > 1 || ay > 1) {
                    int addx = ax == 0 ? 0 : (x[j - 1] - x[j]) / ax;
                    int addy = ay == 0 ? 0 : (y[j - 1] - y[j]) / ay;
                    x[j] += addx;
                    y[j] += addy;
                    m[mp(x[n - 1], y[n - 1])]++;
                }
            }
        }
    }
    cout << m.size();
    return 0;
}