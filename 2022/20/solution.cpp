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
typedef vector<ll> VI;
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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
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
    ll v;
    VPII a;
    int ind = 0;
    ll key = 811589153;
    while (cin >> v) {
        a.pb(mp(v * key, ind));
        ++ind;
    }

    int n = a.size();
    FOR(i,n) {
        cout <<a[i].first << " ";
    }
    cout << "\n";
    FOR(tt,10) {
        FOR(i, n) {
            int pos = 0;
            FOR(j, n) {
                if (a[j].second == i) {
                    pos = j;
                    break;
                }
            }
            ll now = a[pos].first;
            if (now == 0) {
                continue;
            }
            ll add = abs(now) / now;
            ll to = abs(now) % (n - 1);
            FOR(j, to) {
                int next = (pos + add + n) % n;
                swap(a[pos], a[next]);
                pos = next;
            }
        }
        FOR(i,n) {
            cout <<a[i].first << " ";
        }
        cout << "\n";
    }

    int pos = 0;
    FOR(i, n) {
        if (a[i].first == 0) {
            pos = i;
            break;
        }
    }
    ll res = 0;
    FOR(i, 3001) {
        if (i != 0 && i % 1000 == 0) {
            cout << a[pos].first << " ";
            res += a[pos].first;
        }
        pos = (pos + 1 + n) % n;
    }
    cout << res;

    return 0;
}