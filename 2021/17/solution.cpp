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
    int x1 = 20, x2 = 30;
    int y1 = -5, y2 = -10;
    x1 = 124, x2 = 174;
    y1 = -86, y2 = -123;
    int resy = 0;
    int cnt = 0;
    REP(x, 1, 200) {
        REP(y, -200, 200) {
            int xx = x;
            int yy = y;
            int xs = 0;
            int ys = 0;
            int mxy = 0;
            while (xs < x2 && ys > y2) {
                xs += xx;
                ys += yy;
                mxy = max(mxy, ys);
                //cout << xs << " " << ys << "\n";
                if (xs >= x1 && xs <= x2 && ys <= y1 && ys >= y2) {
                    resy = max(resy, mxy);
                    ++cnt;
                    break;
                }
                if (xx > 0) {
                    xx--;
                }
                yy--;
            }
        }
    }
    cout << resy << " " << cnt;
    return 0;
}
