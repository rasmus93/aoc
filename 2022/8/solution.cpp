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

int a[205][205];
int dx[4] = {0, -1, 0, 1};
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
    int n;
    int k = 0;
    while (cin >> s) {
        n = s.size();
        FOR(j, s.size()) {
            a[k][j] = s[j] - '0';
        }
        ++k;
    }
    int res = 0;
    FOR(i, n) {
        FOR(j, n) {
            int seen1 = 0;
            for (int i1 = i - 1; i1 >= 0; --i1) {
                ++seen1;
                if (a[i1][j] >= a[i][j]) {
                    break;
                }
            }
            int seen2= 0;
            REP(i1, i + 1, n) {
                ++seen2;
                if (a[i1][j] >= a[i][j]) {
                    break;
                }
            }
            int seen3 = 0;
            for (int j1 = j - 1; j1 >= 0; --j1) {
                ++seen3;
                if (a[i][j1] >= a[i][j]) {
                    break;
                }
            }
            int seen4 = 0;
            REP(j1, j + 1, n) {
                ++seen4;
                if (a[i][j1] >= a[i][j]) {
                    break;
                }
            }
            int now = seen1 * seen2 * seen3 * seen4;
            res = max(res,now);
        }
    }
    cout << res;
    return 0;
}