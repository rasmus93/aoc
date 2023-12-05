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

int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
//x >= 0 && y >= 0 && x < n && y < m

struct pt {
    int x, y, z;
};

const int N = 30;
int used[N][N][N];

void go(int x, int y, int z) {
    queue<pt> q;
    pt p;
    p.x = x;
    p.y = y;
    p.z = z;
    q.push(p);
    used[x][y][z] = 2;
    while (!q.empty()) {
        pt now = q.front();
        q.pop();
        FOR(k, 6) {
            x = now.x + dx[k];
            y = now.y + dy[k];
            z = now.z + dz[k];
            if (x >= 0 && y >= 0 && z >= 0 && x < N && y < N && z < N
                && !used[x][y][z]) {
                used[x][y][z] = 2;
                pt next;
                next.x = x;
                next.y = y;
                next.z = z;
                q.push(next);
            }
        }
    }
}

int solve() {
    int res = 0;
    FOR(i, N) {
        FOR(j,N) {
            FOR(k,N) {
                if (used[i][j][k]) {
                    continue;
                }
                FOR(kk,6) {
                    int x = i + dx[kk];
                    int y = j + dy[kk];
                    int z = k + dz[kk];
                    if (x >= 0 && y >= 0 && z >= 0 && x < N && y < N && z < N
                        && used[x][y][z]) {
                        ++res;
                    }
                }
            }
        }
    }
    return res;
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
    vector<pt> a;
    while (cin >> s) {
        stringstream ss(s);
        vector<string> values = scan_strings(ss, ',');
        int x = atoi(values[0].c_str()) + 5;
        int y = atoi(values[1].c_str()) + 5;
        int z = atoi(values[2].c_str()) + 5;
        pt v;
        v.x = x;
        v.y = y;
        v.z = z;
        a.pb(v);
        used[x][y][z] = 1;
    }
    go(0, 0, 0);
    int res = 0;
    FOR(i, a.size()) {
        pt p1 = a[i];
        int sides = 6;
        FOR(j, a.size()) {
            if (i == j) {
                continue;
            }
            pt p2 = a[j];
            if (p1.x == p2.x && p1.y == p2.y && abs(p1.z - p2.z) == 1
                || p1.x == p2.x && p1.z == p2.z && abs(p1.y - p2.y) == 1
                || p1.y == p2.y && p1.z == p2.z && abs(p1.x - p2.x) == 1) {
                --sides;
            }
        }
        res += sides;
    }
    cout << res - solve();
    return 0;
}

