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
    string s1,s2;
    int res = 0;
    while(getline(cin, s1)) {
        getline(cin, s2);
        //cout << s1 << "-\n" << s2 << "-\n";
        stringstream ss(s2);
        string v;
        while (getline(ss, v, ' ')) {
            int n = v.size();
            if (n == 2 || n  == 4 || n == 3 || n == 7) {
                ++res;
            }
        }
    }
    cout << res;
    return 0;
}
