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
    int g = 1;
    ll res = 0;
    while (cin >> s >> s) {
        getline(cin, s);
        stringstream ss(s);
        vector<string> values = scan_strings(ss, ';');
        ll mxx = 0;
        ll mxy = 0;
        ll mxz = 0;
        FOR(i, values.size()) {
            stringstream ss2(values[i]);
            vector<string> a = scan_strings(ss2, ',');
            ll x = 0;
            ll y = 0;
            ll z = 0;
            FOR(j, a.size()) {
                stringstream ss3(a[j]);
                vector<string> b = scan_strings(ss3, ' ');
                if (b[2] == "red") {
                    x += atoi(b[1].c_str());
                }
                if (b[2] == "green") {
                    y += atoi(b[1].c_str());
                }
                if (b[2] == "blue") {
                    z += atoi(b[1].c_str());
                }
            }
            mxx = max(mxx,x);
            mxy = max(mxy,y);
            mxz = max(mxz, z);
        }
        res += mxx * mxy * mxz;

        g++;
    }
    cout << res;
    return 0;
}