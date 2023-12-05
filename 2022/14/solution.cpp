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

int a[1000][1000];

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
    int prevx = -1;
    int prevy = -1;
    int mxx = -1;
    while (cin >> s) {
        if (s == "end") {
            prevx = -1;
            prevy = -1;
            continue;
        }
        if (s == "->") {
            continue;
        }
        stringstream ss(s);
        vector<string> values = scan_strings(ss, ',');
        int x = atoi(values[1].c_str());
        int y = atoi(values[0].c_str());
        mxx = max(x, mxx);
        if (prevx == -1) {
            prevx = x;
            prevy = y;
            continue;
        }
        REPE(i, min(x, prevx), max(x, prevx)) {
            REPE(j, min(y, prevy), max(y, prevy)) {
                a[i][j] = 1;
            }
        }
        prevx = x;
        prevy = y;
    }
    REPE(i,mxx + 2,mxx + 2) {
       REP(j,0,1000) {
           a[i][j] = 1;
       }
    }

    int res = 0;
    while (true) {
        int x = 0;
        int y = 500;
        while (x < mxx + 10) {
            if (a[x + 1][y] == 0) {
                ++x;
                continue;
            }
            if (a[x + 1][y - 1] == 0) {
                ++x;
                --y;
                continue;
            }
            if (a[x + 1][y + 1] == 0) {
                ++x;
                ++y;
                continue;
            }
            break;
        }
        if (x == 0 && y == 500) {
            break;
        }
        ++res;
        a[x][y] = 2;
    }
    cout << res + 1;
    return 0;
}