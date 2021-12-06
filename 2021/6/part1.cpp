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
    VI a;
    while (getline(ss, v, ',')) {
        a.pb(atoi(v.c_str()));
    }
    FOR(tt,80) {
        int n = a.size();
        FOR(i, n) {
            a[i]--;
            if (a[i] == -1) {
                a.pb(8);
                a[i] = 6;
            }
            //cout << a[i] << ",";
        }
        //cout << "\n";
    }
    cout << a.size();
    return 0;
}
