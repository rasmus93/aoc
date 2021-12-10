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

ll cost[4] = {3, 57, 1197, 25137};
string x = "([{<";
string y = ")]}>";

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    string s;
    vector<string> incomplete;
    vector<vector<char>> b;
    while (cin >> s) {
        int n = s.size();
        vector<char> a;
        int bad = -1;
        int z = 0;
        FOR(i, n) {
            char c = s[i];
            if (contains(x, c)) {
                a.pb(c);
                continue;
            }
            FOR(k, 4) {
                if (c == y[k]) {
                    if (a.back() != x[k]) {
                        bad = i;
                        z = k;
                        break;
                    }
                }
            }
            if (bad != -1) {
                break;
            }
            a.pop_back();
        }
        if (bad == -1) {
            incomplete.pb(s);
            b.pb(a);
        }
    }

    vector<ll> res;
    FOR(i, incomplete.size()) {
        vector<char> now = b[i];
        ll cur = 0;
        while (!now.empty()) {
            char c = now.back();
            cur *= 5;
            FOR(k,4) {
                if (c == x[k]) {
                    cur += k + 1;
                }
            }
            now.pop_back();
        }
        res.pb(cur);
    }
    sort(res.begin(), res.end());
    cout << res[res.size() / 2];
    return 0;
}
