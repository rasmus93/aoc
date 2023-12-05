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
typedef pair<int, int> PII;
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

//stringstream ss(s);
//vector<string> values = scan_strings(ss, ',');
vector<string> scan_strings(stringstream &ss, char delim) {
    string v;
    vector<string> res;
    while (getline(ss, v, delim)) {
        res.pb(v);
    }
    return res;
}

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dd[4][4] = {
        {0, 1, 2, 1},
        {5, 6, 7, 6},
        {0, 3, 5, 3},
        {2, 4, 7, 4}
};
//x >= 0 && y >= 0 && x < n && y < m

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
    VPII a;
    map<PII, int> m;
    int z = 0;
    int add = 1000;
    while (cin >> s) {
        FOR(j, s.size()) {
            if (s[j] == '#') {
                a.pb(mp(z + add, j + add));
                m[mp(z + add, j + add)] = 1;
            }
        }
        ++z;
    }

    int n = a.size();
    FOR(tt, 1000) {
        // new - old
        vector<pair<PII, PII>> a2;
        map<PII, int> m2;
        FOR(i, n) {
            int x = a[i].first;
            int y = a[i].second;
            bool no_move = true;
            FOR(k, 8) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (m.count(mp(nx, ny))) {
                    no_move = false;
                    break;
                }
            }
            if (no_move) {
                a2.pb(mp(mp(x, y), mp(x, y)));
                m2[mp(x, y)]++;
                continue;
            }

            int to = -1;
            FOR(j, 4) {
                int jj = (j + tt) % 4;
                bool can = true;
                FOR(k, 3) {
                    int nx = x + dx[dd[jj][k]];
                    int ny = y + dy[dd[jj][k]];
                    if (m.count(mp(nx, ny))) {
                        can = false;
                        break;
                    }
                }
                if (can) {
                    to = jj;
                    break;
                }
            }
            if (to == -1) {
                a2.pb(mp(mp(x, y), mp(x, y)));
                m2[mp(x, y)]++;
                continue;
            }
            int nx = x + dx[dd[to][3]];
            int ny = y + dy[dd[to][3]];
            a2.pb(mp(mp(nx, ny), mp(x, y)));
            m2[mp(nx, ny)]++;
        }

        VPII new_a;
        map<PII, int> new_m;
        FOR(i, n) {
            int nx = a2[i].first.first;
            int ny = a2[i].first.second;
            int x = a2[i].second.first;
            int y = a2[i].second.second;
            if (m2[mp(nx, ny)] > 1) {
                new_a.pb(mp(x, y));
                new_m[mp(x, y)] = 1;
            } else {
                new_a.pb(mp(nx, ny));
                new_m[mp(nx, ny)] = 1;
            }
        }
        if (new_m.size() != new_a.size()) {
            throw 1;
        }
        swap(new_m, m);
        swap(new_a, a);

        sort(a.begin(), a.end());
        sort(new_a.begin(), new_a.end());
        bool ok = true;
        FOR(i,n) {
            if (a[i].first != new_a[i].first || a[i].second != new_a[i].second) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << tt + 1;
            return 0;
        }

        /*int mxx = -1;
        int mxy = -1;
        int mnx = inf;
        int mny = inf;
        FOR(i, a.size()) {
            mxx = max(mxx, a[i].first);
            mnx = min(mnx, a[i].first);
            mxy = max(mxy, a[i].second);
            mny = min(mny, a[i].second);
        }
        REPE(i,mnx,mxx) {
            REPE(j,mny,mxy) {
                if (m.count(mp(i,j))) {
                    cout << "#";
                } else {
                    cout << ".";
                }
            }
            cout << "\n";
        }
        cout << "\n";*/
    }

    int mxx = -1;
    int mxy = -1;
    int mnx = inf;
    int mny = inf;
    FOR(i, a.size()) {
        mxx = max(mxx, a[i].first);
        mnx = min(mnx, a[i].first);
        mxy = max(mxy, a[i].second);
        mny = min(mny, a[i].second);
    }
    cout << (mxx - mnx + 1) * (mxy - mny + 1) - n;
    return 0;
}