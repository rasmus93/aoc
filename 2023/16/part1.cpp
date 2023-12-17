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


bool contains(string &s, char c) {
    return s.find(c) != string::npos;
}


string scan(stringstream &ss, char delim) {
    string v;
    getline(ss, v, delim);
    return v;
}

const ll inf = (ll) 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll myRand(ll B) {
    return (unsigned long long) rng() % B;
}

//stringstream ss(s);
//vector<string> values = scan_strings(ss, ',');
vector<string> scan_strings(string &s, char delim) {
    stringstream ss(s);
    string v;
    vector<string> res;
    while (getline(ss, v, delim)) {
        res.pb(v);
    }
    return res;
}

vector<ll> scan_lls(string &s, char delim) {
    stringstream ss(s);
    string v;
    vector<ll> res;
    while (getline(ss, v, delim)) {
        res.pb(atol(v.c_str()));
    }
    return res;
}

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool check(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool pred(const pair<string, ll> &i, const pair<string, ll> &j) {
    return false;
}

struct pt {
    int x;
    int y;
    int from;
};

int n, m;
vector<VVI> b(4, VVI(5));

void pre() {
    FOR(i, 4) {
        FOR(j, 5) {
            VI next;
            b[i][j] = next;
        }
    }
    //0
    int from = 0;
    b[from][0].pb(0);
    b[from][1].pb(1);
    b[from][1].pb(3);
    b[from][2].pb(0);
    b[from][3].pb(1);
    b[from][4].pb(3);
    //1
    from = 1;
    b[from][0].pb(1);
    b[from][1].pb(1);
    b[from][2].pb(0);
    b[from][2].pb(2);
    b[from][3].pb(0);
    b[from][4].pb(2);
    //2
    from = 2;
    b[from][0].pb(2);
    b[from][1].pb(1);
    b[from][1].pb(3);
    b[from][2].pb(2);
    b[from][3].pb(3);
    b[from][4].pb(1);
    //3
    from = 3;
    b[from][0].pb(3);
    b[from][1].pb(3);
    b[from][2].pb(0);
    b[from][2].pb(2);
    b[from][3].pb(2);
    b[from][4].pb(0);
}

int solve(VVI &a) {
    n = a.size();
    m = a[0].size();
    queue<pt> q;
    q.push(pt{0, 0, 0});
    vector<VVI> used(n, VVI(m, VI(4, 0)));
    used[0][0][0] = 1;
    while (!q.empty()) {
        pt v = q.front();
        q.pop();
        FOR(i, b[v.from][a[v.x][v.y]].size()) {
            int to = b[v.from][a[v.x][v.y]][i];
            int x = v.x + dx[to];
            int y = v.y + dy[to];
            if (check(x, y, n, m)) {
                if (used[x][y][to] == 0) {
                    used[x][y][to] = 1;
                    q.push(pt{x, y, to});
                }
            }
        }
    }
    int res = 0;
    FOR(i, n) {
        FOR(j, m) {
            bool need = false;
            FOR(k, 4) {
                if (used[i][j][k]) {
                    need = true;
                    break;
                }
            }
            if (need) {
                cerr << "#";
                ++res;
            } else {
                cerr << ".";
            }
        }
        cerr << "\n";
    }
    return res;
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
#ifdef DEBUG
    if (getenv("SUBMIT") == NULL) {
        freopen("local.txt", "r", stdin);
    } else {
        freopen("input.txt", "r", stdin);
    }
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s;
    VVI a;
    while (cin >> s) {
        VI now;
        FOR(i, s.size()) {
            int v;
            if (s[i] == '.') {
                v = 0;
            } else if (s[i] == '|') {
                v = 1;
            } else if (s[i] == '-') {
                v = 2;
            } else if (s[i] == '\\') {
                v = 3;
            } else {
                v = 4;
            }
            now.pb(v);
        }
        a.pb(now);
    }
    pre();
    cout << solve(a);
    return 0;
}
