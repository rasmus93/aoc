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

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
//x >= 0 && y >= 0 && x < n && y < m

struct pt {
    int ore_cost_ore;
    int clay_cost_ore;
    int obs_cost_ore;
    int obs_cost_clay;
    int geode_cost_ore;
    int geode_cost_obs;
};

struct vt {
    int ores = 0;
    int clays = 0;
    int obs = 0;
    int geodes = 0;

    bool operator<(const vt &o) const {
        return ores < o.ores
               || ores == o.ores && clays < o.clays
               || ores == o.ores && clays == o.clays && obs < o.obs
               || ores == o.ores && clays == o.clays && obs == o.obs && geodes < o.geodes;
    }
};

struct robots {
    int ores = 0;
    int clays = 0;
    int obs = 0;
    int geodes = 0;

    bool operator<(const robots &o) const {
        return ores < o.ores
               || ores == o.ores && clays < o.clays
               || ores == o.ores && clays == o.clays && obs < o.obs
               || ores == o.ores && clays == o.clays && obs == o.obs && geodes < o.geodes;
    }
};

map<tuple<vt, robots, int>, int> m;

void add(vt &v, robots &r) {
    v.ores += r.ores;
    v.obs += r.obs;
    v.clays += r.clays;
    v.geodes += r.geodes;
}

int mx = -1;

int dfs(pt &v, vt now, robots r, int left = 24) {
    if (r.clays > 10 || r.ores > 10 || r.obs > 10) {
        return 0;
    }
    tuple key = tuple(now, r, left);
    if (m.count(key)) {
        return m[key];
    }
    if (left == 0) {
        return now.geodes;
    }

    int res = 0;
    vt next_vt;
    robots next_r;

    if (v.geode_cost_ore <= now.ores && v.geode_cost_obs <= now.obs) {
        next_vt = now;
        next_r = r;
        next_vt.ores -= v.geode_cost_ore;
        next_vt.obs -= v.geode_cost_obs;
        add(next_vt, next_r);
        next_r.geodes++;
        res = max(res, dfs(v, next_vt, next_r, left - 1));
    }
    if (v.obs_cost_ore <= now.ores && v.obs_cost_clay <= now.clays) {
        next_vt = now;
        next_r = r;
        next_vt.ores -= v.obs_cost_ore;
        next_vt.clays -= v.obs_cost_clay;
        add(next_vt, next_r);
        next_r.obs++;
        res = max(res, dfs(v, next_vt, next_r, left - 1));
    }
    if (v.clay_cost_ore <= now.ores) {
        next_vt = now;
        next_r = r;
        next_vt.ores -= v.clay_cost_ore;
        add(next_vt, next_r);
        next_r.clays++;
        res = max(res, dfs(v, next_vt, next_r, left - 1));
    }
    if (v.ore_cost_ore <= now.ores) {
        next_vt = now;
        next_r = r;
        next_vt.ores -= v.ore_cost_ore;
        add(next_vt, next_r);
        next_r.ores++;
        res = max(res, dfs(v, next_vt, next_r, left - 1));
    }
    add(now, r);
    res = max(res, dfs(v, now, r, left - 1));

    m[key] = res;
    if (res > mx) {
        mx = res;
        cerr << mx << "\n";
    }
    return res;
}

int bfs(pt &p, vt v, robots r, int left = 24) {
    int mx_ore = max(
            max(p.ore_cost_ore, p.clay_cost_ore),
            max(p.obs_cost_ore, p.geode_cost_ore)
    );
    int res = 0;
    deque<tuple<vt, robots, int>> q;
    tuple key = tuple(v, r, left);
    q.push_back(key);
    while (!q.empty()) {
        tuple<vt, robots, int> now = q.back();
        q.pop_back();
        v = get<0>(now);
        r = get<1>(now);
        left = get<2>(now);
        res = max(res, v.geodes);
        if (left == 0) {
            continue;
        }
        v.ores = min(v.ores, left * mx_ore - r.ores * (left - 1));
        v.clays = min(v.clays, left * p.obs_cost_clay - r.clays * (left - 1));
        v.obs = min(v.obs, left * p.geode_cost_obs - r.obs * (left - 1));
        now = tuple(v, r, left);
        /*printf("(%d, %d, %d, %d, %d, %d, %d, %d, %d)\n",
               r.ores, r.clays, r.obs, r.geodes,
               v.ores, v.clays, v.obs, v.geodes,
               left);*/
        if (m.count(now)) {
            continue;
        }
        m[now] = 1;

        vt next_vt = v;
        robots next_r = r;
        add(next_vt, next_r);
        q.push_back(tuple<vt, robots, int>(next_vt, next_r, left - 1));
        if (p.geode_cost_ore <= v.ores && p.geode_cost_obs <= v.obs) {
            next_vt = v;
            next_r = r;
            next_vt.ores -= p.geode_cost_ore;
            next_vt.obs -= p.geode_cost_obs;
            add(next_vt, next_r);
            next_r.geodes++;
            q.push_back(tuple<vt, robots, int>(next_vt, next_r, left - 1));
        } else {
            if (p.obs_cost_ore <= v.ores && p.obs_cost_clay <= v.clays
                && r.obs < p.geode_cost_obs) {
                next_vt = v;
                next_r = r;
                next_vt.ores -= p.obs_cost_ore;
                next_vt.clays -= p.obs_cost_clay;
                add(next_vt, next_r);
                next_r.obs++;
                q.push_back(tuple<vt, robots, int>(next_vt, next_r, left - 1));
            }
            if (p.clay_cost_ore <= v.ores
                && r.clays < p.obs_cost_clay) {
                next_vt = v;
                next_r = r;
                next_vt.ores -= p.clay_cost_ore;
                add(next_vt, next_r);
                next_r.clays++;
                q.push_back(tuple<vt, robots, int>(next_vt, next_r, left - 1));
            }
            if (p.ore_cost_ore <= v.ores
                && r.ores < mx_ore) {
                next_vt = v;
                next_r = r;
                next_vt.ores -= p.ore_cost_ore;
                add(next_vt, next_r);
                next_r.ores++;
                q.push_back(tuple<vt, robots, int>(next_vt, next_r, left - 1));
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
    int ind = 1;
    int res = 0;
    while (cin >> s >> s >> s >> s >> s >> s) {
        pt now;
        cin >> now.ore_cost_ore;
        cin >> s >> s >> s >> s >> s;
        cin >> now.clay_cost_ore;
        cin >> s >> s >> s >> s >> s;
        cin >> now.obs_cost_ore >> s >> s >> now.obs_cost_clay;
        cin >> s >> s >> s >> s >> s;
        cin >> now.geode_cost_ore >> s >> s >> now.geode_cost_obs;
        cin >> s;

        cerr << now.ore_cost_ore << " " << now.clay_cost_ore << " ";
        cerr << now.obs_cost_ore << " " << now.obs_cost_clay << " ";
        cerr << now.geode_cost_ore << " " << now.geode_cost_obs << "\n";

        vt v;
        robots r;
        r.ores = 1;
        m.clear();
        int res_now = bfs(now, v, r, 32);
        cerr << res_now << "\n";
        res += ind * res_now;
        ++ind;
    }
    cout << res;
    return 0;
}
