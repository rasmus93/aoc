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

ll cost[4] = {3,57,1197,25137};

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    string s;
    ll res = 0;
    while(cin >> s) {
        int n = s.size();
        vector<char> a;
        int bad = -1;
        int z = 0;
        FOR(i,n) {
            char c = s[i];
            if (c == '(' || c == '[' || c== '{' || c == '<') {
                a.pb(c);
            } else {
                if (c == ')') {
                    if (a.back() != '(') {
                        bad = i;
                        z = 0;
                        break;
                    }
                    a.pop_back();
                } else if (c == ']') {
                    if (a.back() != '[') {
                        bad = i;
                        z = 1;
                        break;
                    }
                    a.pop_back();
                } else if (c == '}') {
                    if (a.back() != '{') {
                        bad = i;
                        z = 2;
                        break;
                    }
                    a.pop_back();
                } else if (c == '>') {
                    if (a.back() != '<') {
                        bad = i;
                        z = 3;
                        break;
                    }
                    a.pop_back();
                }
            }
        }
        if (bad != -1) {
            cout << s << " " << bad << " " << z << "\n";
            res += cost[z];
            continue;
        }
    }
    cout << res;
    return 0;
}
