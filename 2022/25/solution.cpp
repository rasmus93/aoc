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
int dy[4] = {1, 0, -1, 0};
//x >= 0 && y >= 0 && x < n && y < m

int go(char c) {
    if (c == '2') {
        return 2;
    }
    if (c == '1') {
        return 1;
    }
    if (c == '0') {
        return 0;
    }
    if (c == '-') {
        return -1;
    }
    return -2;
}

char go2(int c) {
    if (c == 2) {
        return '2';
    }
    if (c == 1) {
        return '1';
    }
    if (c == 0) {
        return '0';
    }
    if (c == -1) {
        return '-';
    }
    if (c == -2) {
        return '=';
    }
    throw 1;
}

ll solve(string s) {
    int n = s.size();
    ll now = 0;
    ll st = 1;
    for (int i = n - 1; i >= 0; --i) {
        ll v = go(s[i]);
        now += v * st;
        st *= 5;
    }
    return now;
}

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
    ll res = 0;
    while (cin >> s) {
        res += solve(s);
    }
    cout << res << "\n";
    ll st = 1;
    while (st < res) {
        st *= 5;
    }
    while (st) {
        int cnt = 0;
        int sign = res < 0 ? -1 : (res > 0 ? 1 : 0);
        cnt = (res / st);
        ll mx = (st / 2);
        if (abs(res - cnt * st) > mx) {
            cnt += sign;
        }

        if (abs(cnt) > 2) {
            throw 1;
        }
        cout << go2(cnt);
        res -= cnt * st;

        st /= 5;
    }
    cout << "\n";
    cout << solve("02-0-020-1==1021=--01");
    return 0;
}