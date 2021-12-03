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


int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    //getline(cin, str)
    //stringstream(str)
    //while(getline(str,newstr,' ') { use newstr }
    string v;
    vector<string> s;
    while (cin >> v) {
        s.pb(v);
    }
    int n = s.size();
    int m = v.size();
    VI a(m);//0
    VI b(m);//1
    FOR(i, n) {
        FOR(j, m) {
            if (s[i][j] == '0') {
                a[j]++;
            } else {
                b[j]++;
            }
        }
    }
    ll x = 0;
    ll y = 0;
    ll st = 1;
    for (int j = m - 1; j >= 0; --j) {
        if (a[j] >= b[j]) {
            x += st * 0;
            y += st * 1;
        } else {
            x += st * 1;
            y += st * 0;
        }
        st *= 2;
    }
    cout << x * y;
    return 0;
}
