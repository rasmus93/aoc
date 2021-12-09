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

int n;
int m;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool check(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

bool used[105][105];

void go(VVI &a, int i, int j, ll &res) {
    used[i][j] = true;

    FOR(k,4) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (check(x,y) && !used[x][y] && a[x][y] > a[i][j] && a[x][y] != 9) {
            ++res;
            go(a,x,y, res);
        }
    }
}

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

    n = a.size();
    m = a[0].size();

    VPII points;
    FOR(i, a.size()) {
        FOR(j, a[i].size()) {
            bool ok = true;
            FOR(k, 4) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (check(x,y)) {
                    if (a[x][y] <= a[i][j]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                points.pb(mp(i,j));
            }
        }
    }

    vector<ll> res;
    FOR(i,points.size()) {
        int x = points[i].first;
        int y = points[i].second;
        ll now = 1;
        go(a,x,y,now);
        res.pb(now);
    }
    sort(res.begin(), res.end());
    reverse(res.begin(), res.end());
    cout << res[0] * res[1] * res[2];
    return 0;
}
