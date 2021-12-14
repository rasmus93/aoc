#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for (int i=0; i<n; ++i)
#define FORE(i, n) for (int i=0; i<=n; ++i)
#define REP(i, a, b) for (int i=a; i<b; ++i)
#define REPE(i, a, b) for (int i=a; i<=b; ++i)
#define mp make_pair
#define pb push_back

typedef long double dbl;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int ll;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;

bool pred(const int &i, const int &j) {
    return i < j;
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

int scan_int(stringstream &ss, char delim) {
    return atoi(scan(ss,delim).c_str());
}

vector<string> scan_strings(stringstream &ss, char delim) {
    string v;
    vector<string> res;
    while (getline(ss, v, delim)) {
        res.pb(v);
    }
    return res;
}

vector<ll> scan_ints(stringstream &ss, char delim) {
    string v;
    vector<ll> res;
    while (getline(ss, v, delim)) {
        res.pb(atol(v.c_str()));
    }
    return res;
}


int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<char> a(n);
    FOR(i,n) {
        a[i] = s[i];
    }
    string from,z,to;
    vector<char> x;
    vector<char> y;
    vector<char> c;
    while(cin >> from >> z >> to) {
        char xx = from[0];
        char yy = from[1];
        char cc = to[0];
        x.pb(xx);
        y.pb(yy);
        c.pb(cc);
    }
    int m = x.size();
    FOR(tt,10) {
        vector<char> b;
        n = a.size();
        b.pb(a[0]);
        REP(i,1,n) {
            char xx = a[i - 1];
            char yy = a[i];
            FOR(j,m) {
                if (x[j] == xx && y[j] == yy) {
                    b.pb(c[j]);
                    break;
                }
            }
            b.pb(a[i]);
        }
        swap(a,b);
        cerr << tt << "\n";
    }

    vector<int> cnt(26);
    FOR(i,a.size()) {
        cnt[a[i] - 'A']++;
    }
    int mx = -1;
    int mn = (int)1e9;
    FOR(i,26) {
        mx = max(cnt[i],mx);
        if (cnt[i] != 0) {
            mn = min(cnt[i], mn);
        }
    }
    cout << mx - mn;
    return 0;
}
