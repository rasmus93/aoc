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
typedef vector<ll> VI;
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

struct monkey {
    string op;
    string v;
    int divisible;
    int to_true;
    int to_false;
};

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
    VVI a;
    vector<monkey> m;
    int n = 0;
    //ll mod = 3;
    ll mod = 1;
    while (cin >> s) {
        cin >> s >> s >> s;
        cin.get();
        getline(cin,s);
        stringstream ss(s);
        vector<string> values = scan_strings(ss, ' ');
        VI now;
        FOR(i,values.size()) {
            now.pb(atol(values[i].c_str()));
        }
        monkey cur;
        cin >> s >> s >> s >> s >> cur.op >> cur.v;
        cin >> s >> s >> s >> cur.divisible;
        cin >> s >> s >> s >> s >> s >> cur.to_true;
        cin >> s >> s >> s >> s >> s >> cur.to_false;
        ++n;
        mod *= cur.divisible;
        a.pb(now);
        m.pb(cur);
    }
    VI res(n,0);
    FOR(tt,10000) {
        FOR(i, n) {
            FOR(j,a[i].size()) {
                res[i]++;
                ll now = a[i][j];
                ll v;
                if (m[i].v == "old") {
                    v = now;
                } else {
                    v = atol(m[i].v.c_str());
                }
                if (m[i].op == "*") {
                    now *= v;
                } else if(m[i].op == "+") {
                    now += v;
                }
                now %= mod;
                if (now % m[i].divisible == 0) {
                    a[m[i].to_true].pb(now);
                } else {
                    a[m[i].to_false].pb(now);
                }
            }
            a[i].clear();
        }
    }
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    cout << res[0] * res[1];
    return 0;
}

//20743487134