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


void go(int m, vector<string> &s, VI &a, VI &b) {
    int n = s.size();
    FOR(i, n) {
        FOR(j, m) {
            if (s[i][j] == '0') {
                a[j]++;
            } else {
                b[j]++;
            }
        }
    }
}

void findS(vector<string> &s, int &pos, char c) {
    vector<string> news;
    FOR(i,s.size()) {
        if (s[i][pos] == c) {
            news.pb(s[i]);
        }
    }
    swap(news,s);
    ++pos;
}

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
    vector<string> s1;
    vector<string> s2;
    while (cin >> v) {
        s1.pb(v);
        s2.pb(v);
    }
    int m = v.size();
    int pos = 0;
    while(s1.size() > 1) {
        VI a(m);
        VI b(m);
        go(m, s1, a, b);

        char c;
        if (a[pos] > b[pos]) {
            c = '0';
        } else {
            c = '1';
        }
        findS(s1,pos,c);
    }

    pos = 0;
    while(s2.size() > 1) {
        VI a(m);
        VI b(m);
        go(m, s2, a, b);

        char c;
        if (a[pos] <= b[pos]) {
            c = '0';
        } else {
            c = '1';
        }
        findS(s2,pos,c);
    }

    ll x = 0;
    ll y = 0;
    ll st = 1;
    for (int j = m - 1; j >= 0; --j) {
        x += (s1[0][j] - '0') * st;
        y += (s2[0][j] - '0') * st;
        st *= 2;
    }
    cout << x * y;
    return 0;
}
