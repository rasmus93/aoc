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

const int n = 1005;
int a[n][n];

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int x1, y1;
    int x2, y2;
    char c;
    string s;

    while (cin >> x1 >> c >> y1 >> s >> x2 >> c >> y2) {
        //cout << x1 << " " << y1 << "|" << x2 << " " << y2 << "\n";
        if (x1 != x2 && y1 != y2) {
            continue;
        }
        if (x1 == x2) {
            if (y1 > y2) {
                swap(y1, y2);
            }
            REPE(i, y1, y2) {
                a[i][x1]++;
            }
        } else {
            if (x1 > x2) {
                swap(x1, x2);
            }
            REPE(i, x1, x2) {
                a[y1][i]++;
            }
        }
    }
    int res = 0;
    FOR(i, n) {
        FOR(j, n) {
            if (a[i][j] >= 2) {
                ++res;
            }
        }
    }
    cout << res;
    return 0;
}
