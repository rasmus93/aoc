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


bool go(VVI &a, vector<VB> &used) {
    int n = a.size();
    ll res = 0;
    FOR(i,n) {
        FOR(j,n) {
            a[i][j]++;
        }
    }
    while (true) {
        bool exit = true;
        FOR(i, n) {
            FOR(j, n) {
                if (a[i][j] > 9 && !used[i][j]) {
                    used[i][j] = true;
                    exit = false;
                    //++res;
                    REPE(x, -1, 1) {
                        REPE(y, -1, 1) {
                            if (x == 0 && y == 0) {
                                continue;
                            }
                            int dx = i + x;
                            int dy = j + y;
                            if (check(dx,dy,n) && !used[dx][dy]) {
                                a[dx][dy]++;
                            }
                        }
                    }
                }
            }
        }
        if (exit) {
            break;
        }
    }

    bool ok = true;
    FOR(i,n) {
        FOR(j,n) {
            if (a[i][j] > 9) {
                a[i][j] = 0;
            }
            if (a[i][j] != 0) {
                ok = false;
            }
        }
    }
    return ok;
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
            b.pb(s[i] - '0');
        }
        a.pb(b);
    }
    int n = a.size();
    ll res = 0;
    FOR(i, 10000) {
        vector<VB> used(n, VB(n));
        if (go(a,used)) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << res;
    return 0;
}
