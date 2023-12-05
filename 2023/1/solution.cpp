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

vector<string> v;

void go() {
    v.pb("one");
    v.pb("two");
    v.pb("three");
    v.pb("four");
    v.pb("five");
    v.pb("six");
    v.pb("seven");
    v.pb("eight");
    v.pb("nine");
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("local.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s;
    ll res = 0;
    go();
    while (cin >> s) {
        s += "zzzzzzzzzzzz";
        ll f = -1;
        ll l = -1;
        FOR(i, s.size()) {
            FOR(j,v.size()) {
                bool ok = true;
                FOR(k,v[j].size()) {
                    if (s[i + k] != v[j][k]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    l = j + 1;
                    if (f == -1) {
                        f = l;
                    }
                }
            }
            cerr << f << " " << l << "\n";
            if (s[i] >= '0' && s[i] <= '9') {
                l = s[i] - '0';
                if (f == -1) {
                    f = l;
                }
            }
        }
        cerr << "\n";
        res += f * 10 + l;
    }
    cout << res;
    return 0;
}