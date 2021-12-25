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
    return atoi(scan(ss, delim).c_str());
}

vector<string> scan_strings(stringstream &ss, char delim) {
    string v;
    vector<string> res;
    while (getline(ss, v, delim)) {
        res.pb(v);
    }
    return res;
}

vector<ll> scan_longs(stringstream &ss, char delim) {
    string v;
    vector<ll> res;
    while (getline(ss, v, delim)) {
        res.pb(atol(v.c_str()));
    }
    return res;
}

VI scan_ints(stringstream &ss, char delim) {
    string v;
    VI res;
    while (getline(ss, v, delim)) {
        res.pb(atoi(v.c_str()));
    }
    return res;
}

const int inf = -(int) 1e9;

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string z;
    vector<string> s;
    while (cin >> z) {
        s.pb(z);
    }
    int n = s.size();
    int m = s[0].size();
    int cnt = 0;
    while (true) {
        vector<string> next(n);
        FOR(i, n) {
            next[i] = s[i];
        }
        bool moved = false;
        //>
        FOR(i, n) {
            FOR(j, m) {
                if (s[i][j] != '>') {
                    continue;
                }
                int j1 = (j + 1) % m;
                if (s[i][j1] == '.') {
                    next[i][j1] = '>';
                    next[i][j] = '.';
                    moved = true;
                }
            }
        }
        swap(s, next);
        FOR(i, n) {
            next[i] = s[i];
        }
        //v
        FOR(i, n) {
            FOR(j, m) {
                if (s[i][j] != 'v') {
                    continue;
                }
                int i1 = (i + 1) % n;
                if (s[i1][j] == '.') {
                    next[i1][j] = 'v';
                    next[i][j] = '.';
                    moved = true;
                }
            }
        }
        swap(s, next);
        if (!moved) {
            break;
        }
        cnt++;
    }
    cout << cnt + 1;
    return 0;
}
