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


bool check(VVI &a) {
    int n = 5;
    FOR(i,n) {
        int now = 0;
        FOR(j,n) {
            now += a[i][j];
        }
        if (now == 5) {
            return true;
        }
    }
    FOR(i,n) {
        int now = 0;
        FOR(j,n) {
            now += a[j][i];
        }
        if (now == 5) {
            return true;
        }
    }
    return false;
}

ll go(VVI &a, VVI &values) {
    int n = 5;
    ll res = 0;
    FOR(i,n) {
        FOR(j,n) {
            if (a[i][j] == 0) {
               res += values[i][j];
            }
        }
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
    string str;
    getline(cin, str);
    stringstream ss(str);
    string v;
    VI num;
    while (getline(ss, v, ',')) {
        num.pb(atoi(v.c_str()));
        //cout << v << "\n";
    }

    int n = 5;
    vector<VVI> boards(100, VVI(5, vector<int>(5)));
    vector<VVI> used(100, VVI(5, vector<int>(5)));
    int m = 0;
    string x;
    while (getline(cin,x)) {
        FOR(i, n) {
            FOR(j, n) {
                cin >> boards[m][i][j];
                used[m][i][j] = 0;
            }
        }
        ++m;
    }

    int win = 0;
    VB wins(m);
    FOR(z, num.size()) {
        FOR(k,m) {
            FOR(i,n) {
                FOR(j,n) {
                    if (boards[k][i][j] == num[z]) {
                        used[k][i][j] = 1;
                    }
                }
            }
        }
        int last = 0;
        FOR(k,m) {
            if (!wins[k] && check(used[k])) {
                ++win;
                last = k;
                wins[k] = true;
            }
        }
        if (win == m) {
            ll res = go(used[last],boards[last]);
            res *= num[z];
            cout << res;
            return 0;
        }
    }
    return 0;
}
