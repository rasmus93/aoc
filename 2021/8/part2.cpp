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

void go(map<int, string> &m, vector<string> &s) {
    int n = s.size();
    vector<bool> used(10);
    //9
    FOR(i, n) {
        int sz = s[i].size();
        if (sz != 6) {
            continue;
        }
        string s4 = m[4];
        bool ok = true;
        FOR(j, s4.size()) {
            if (!contains(s[i], s4[j])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            m[9] = s[i];
            used[i] = true;
            break;
        }
    }
    //0
    FOR(i, n) {
        int sz = s[i].size();
        if (sz != 6 || used[i]) {
            continue;
        }
        string s7 = m[7];
        bool ok = true;
        FOR(j, s7.size()) {
            if (!contains(s[i], s7[j])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            m[0] = s[i];
            used[i] = true;
            break;
        }
    }
    //6
    FOR(i, n) {
        int sz = s[i].size();
        if (sz != 6 || used[i]) {
            continue;
        }
        m[6] = s[i];
        used[i] = true;
    }
    //3
    FOR(i, n) {
        int sz = s[i].size();
        if (sz != 5) {
            continue;
        }
        string s7 = m[7];
        bool ok = true;
        FOR(j, s7.size()) {
            if (!contains(s[i], s7[j])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            m[3] = s[i];
            used[i] = true;
            break;
        }
    }
    //5
    FOR(i, n) {
        int sz = s[i].size();
        if (sz != 5) {
            continue;
        }
        string s6 = m[6];
        bool ok = true;
        FOR(j, sz) {
            if (!contains(s6, s[i][j])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            m[5] = s[i];
            used[i] = true;
            break;
        }
    }
    //6
    FOR(i, n) {
        int sz = s[i].size();
        if (sz != 5 || used[i]) {
            continue;
        }
        m[2] = s[i];
        used[i] = true;
    }
    if (m.size() != 10) {
        throw 1;
    }
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s1, s2;
    ll res = 0;
    while (getline(cin, s1)) {
        map<int, string> m;
        stringstream ss1(s1);
        string v;
        vector<string> s;
        //cout << s1 << "-\n" << s2 << "-\n";
        while (getline(ss1, v, ' ')) {
            if (v == "|") {
                continue;
            }
            int n = v.size();
            sort(v.begin(), v.end());
            if (n == 2) {
                m[1] = v;
            }
            if (n == 4) {
                m[4] = v;
            }
            if (n == 3) {
                m[7] = v;
            }
            if (n == 7) {
                m[8] = v;
            }
            s.pb(v);
        }
        go(m, s);
        map<string, int> values;
        FOR(i, 10) {
            values[m[i]] = i;
        }
        
        getline(cin, s2);
        stringstream ss2(s2);
        ll now = 0;
        while (getline(ss2, v, ' ')) {
            sort(v.begin(), v.end());
            now += values[v];
            now *= 10;
        }
        res += now / 10;
    }
    cout << res;
    //1091609
    return 0;
}
