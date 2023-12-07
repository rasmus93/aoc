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

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool check(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}


string order = "AKQJT98765432";

int hand(string s) {
    map<char, int> m;
    FOR(i, s.size()) {
        m[s[i]]++;
    }
    vector<int> cnt;
    for (auto v: m) {
        cnt.pb(v.second);
    }
    sort(cnt.begin(), cnt.end());
    if (cnt.size() == 1) {
        return 10;
    }
    if (cnt.size() == 2) {
        if (cnt[1] == 4) {
            return 9;
        }
        return 8;
    }
    if (cnt.size() == 3) {
        if (cnt[2] == 3) {
            return 7;
        }
        return 6;
    }
    if (cnt.size() == 4) {
        return 5;
    }
    return 4;
}

int index(char c) {
    FOR(i, order.size()) {
        if (order[i] == c) {
            return i;
        }
    }
    throw 1;
}

bool pred(const pair<string, ll> &i, const pair<string, ll> &j) {
    int x = hand(i.first);
    int y = hand(j.first);
    if (x != y) {
        return x > y;
    }
    FOR(k, 5) {
        if (i.first[k] != j.first[k]) {
            return index(i.first[k]) < index(j.first[k]);
        }
    }
    return false;
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
    vector<pair<string, ll>> a;
    string x;
    ll v;
    while (cin >> x >> v) {
        a.pb(mp(x, v));
    }
    int n = a.size();
    sort(a.begin(), a.end(), pred);
    ll res = 0;
    FOR(i, n) {
        res += a[i].second * (n - i);
    }
    cout << res;
    return 0;
}
