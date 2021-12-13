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

const int N = 4005;

bool a[N][N];

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    string s;
    int n = 0;
    int m = 0;
    while (cin >> s) {
        if (s == "---") {
            break;
        }
        stringstream ss(s);
        string v;
        getline(ss, v, ',');
        int x = atoi(v.c_str());
        getline(ss, v, ',');
        int y = atoi(v.c_str());
        swap(x, y);
        a[x][y] = true;
        n = max(n, x);
        m = max(m, y);
    }
    ++n;
    ++m;

    int nn = 0;
    int mm = 0;

    while (cin >> s >> s >> s) {
        stringstream ss(s);
        string v;
        getline(ss, v, '=');
        string fold = v;
        getline(ss, v, '=');
        int split = atoi(v.c_str());

        if (fold == "x") {
            REP(i, nn, n) {
                int cnt = 1;
                for (int j = mm + split - 1; j >= mm; --j) {
                    a[i][mm + split + cnt] |= a[i][j];
                    ++cnt;
                }
            }
            mm += split + 1;
        } else {
            REP(j, mm, m) {
                int cnt = 1;
                for (int i = nn + split - 1; i >= nn; --i) {
                    a[i][j] |= a[nn + split + cnt][j];
                    ++cnt;
                }
            }
            n = split;
        }
    }

    int res = 0;
    REP(i, nn, n) {
        REP(j, mm, m) {
            if (a[i][j]) {
                ++res;
            }
            cout << (a[i][j] == 1 ? "#" : ".");
        }
        cout << '\n';
    }
    cout << res;
    return 0;
}
