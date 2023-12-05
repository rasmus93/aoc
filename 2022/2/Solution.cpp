#include <bits/stdc++.h>

using namespace std;

#define FOR(i, n) for (int i=0; i<n; ++i)
#define FORE(i, n) for (int i=0; i<=n; ++i)
#define REP(i, a, b) for (int i=a; i<b; ++i)
#define REPE(i, a, b) for (int i=a; i<=b; ++i)
#define mp make_pair
#define pb push_back

typedef long double dbl;
typedef long long int ll;
typedef pair<ll, ll> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;

bool pred(const pair<ll, int> &i, const pair<ll, int> &j) {
    if (i.first == j.first) {
        return i.second > j.second;
    }
    return i.first < j.first;
}

bool contains(string &s, char c) {
    return s.find(c) != string::npos;
}

bool check(int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

string scan(stringstream &ss, char delim) {
    string v;
    getline(ss, v, delim);
    return v;
}

const int inf = (int) 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll myRand(ll B) {
    return (unsigned long long) rng() % B;
}


int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
#ifdef DEBUG
    //freopen("/Users/sergiib/Downloads/to_delete/meta3/worklife_balance_chapter_1_input.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string x, y;
    // 0 > 2, 1 > 0, 2 > 1
    int res = 0;
    while (cin >> x >> y) {
        int a = x[0] - 'A';
        int b = y[0] - 'X';
        int c = 0;
        if (b == 0) {
            if (a == 0) {
                c = 2;
            } else if (a == 1) {
                c = 0;
            } else if (a == 2) {
                c = 1;
            }
            res += 0;
        } else if (b == 1) {
            res += 3;
            c = a;
        } else {
            if (a == 0) {
                c = 1;
            } else if (a == 1) {
                c = 2;
            } else if (a == 2) {
                c = 0;
            }
            res += 6;
        }
        res += c + 1;
        /*res += b + 1;
        if (b == 0 && a == 2 || b == 1 && a == 0 || b == 2 && a == 1) {
            res += 6;
        } else if (a == b) {
            res += 3;
        }*/
    }
    cout << res;
    return 0;
}
