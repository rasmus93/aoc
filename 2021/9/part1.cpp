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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    string s;
    VVI a;
    while (cin >> s) {
        VI b;
        FOR(i, s.size()) {
            int v = s[i] - '0';
            b.pb(v);
        }
        a.pb(b);
    }
    int res = 0;
    VPII points;
    FOR(i, a.size()) {
        FOR(j, a[i].size()) {
            bool ok = true;
            FOR(k, 4) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && y >= 0 && x < a.size() && y < a[i].size()) {
                    if (a[x][y] <= a[i][j]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                res += a[i][j] + 1;
            }
        }
    }
    cout << res;
    return 0;
}
