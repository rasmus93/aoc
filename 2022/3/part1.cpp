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
    string s;
    int res = 0;
    while (cin >> s) {
        int n = s.size();
        int m = n / 2;
        VI a(56);
        FOR(i, m) {
            int v;
            if (s[i] >= 'a' && s[i] <= 'z') {
                v = s[i] - 'a';
                v += 1;
            } else {
                v = s[i] - 'A';
                v += 27;
            }
            a[v]++;
        }
        VI b(56);
        REP(i,m,n) {
            int v;
            if (s[i] >= 'a' && s[i] <= 'z') {
                v = s[i] - 'a';
                v += 1;
            } else {
                v = s[i] - 'A';
                v += 27;
            }
            b[v]++;
        }

        FOR(i,56) {
            if (a[i] != 0 && b[i] != 0) {
                res += i;
            }
        }
    }
    cout << res;
    return 0;
}