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
    int ore_cost;
    int clay_cost;
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


void add(vt &v, robots &r) {
    v.ores += r.ores;
    v.obs += r.obs;
    v.clays += r.clays;
    v.geodes += r.geodes;
}

int mx = -1;

int go(map<tuple<vt, robots, int>, int> &m, pt &v, vt now, robots r, int left = 24) {
    if (r.clays > 10 || r.ores > 10 || r.obs > 10) {
        return now.geodes;
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
        res = max(res, go(m, v, next_vt, next_r, left - 1));

    }
    if (v.obs_cost_ore <= now.ores && v.obs_cost_clay <= now.clays) {
        next_vt = now;
        next_r = r;
        next_vt.ores -= v.obs_cost_ore;
        next_vt.clays -= v.obs_cost_clay;
        add(next_vt, next_r);
        next_r.obs++;
        res = max(res, go(m, v, next_vt, next_r, left - 1));
    }
    if (v.clay_cost <= now.ores) {
        next_vt = now;
        next_r = r;
        next_vt.ores -= v.clay_cost;
        add(next_vt, next_r);
        next_r.clays++;
        res = max(res, go(m, v, next_vt, next_r, left - 1));

    }
    if (v.ore_cost <= now.ores) {
        next_vt = now;
        next_r = r;
        next_vt.ores -= v.ore_cost;
        add(next_vt, next_r);
        next_r.ores++;
        res = max(res, go(m, v, next_vt, next_r, left - 1));
    }
    add(now, r);
    res = max(res, go(m, v, now, r, left - 1));

    m[key] = res;
    return res;
}

int res = 1;

void go2(int ind, pt v, vt now, robots r, int left = 24) {
    map<tuple<vt, robots, int>, int> m;
    res *= go(m, v, now, r, left);
    cerr << ind << "\n";
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
//#ifdef DEBUG
    //freopen("/Users/sergiib/Downloads/to_delete/meta3/worklife_balance_chapter_1_input.txt", "r", stdin);
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
//#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string s;
    int ind = 1;
    vector<thread> threads;
    while (cin >> s >> s >> s >> s >> s >> s) {
        if (ind == 4) {
            break;
        }
        pt now;
        cin >> now.ore_cost;
        cin >> s >> s >> s >> s >> s;
        cin >> now.clay_cost;
        cin >> s >> s >> s >> s >> s;
        cin >> now.obs_cost_ore >> s >> s >> now.obs_cost_clay;
        cin >> s >> s >> s >> s >> s;
        cin >> now.geode_cost_ore >> s >> s >> now.geode_cost_obs;
        cin >> s;

        cerr << now.ore_cost << " " << now.clay_cost << " ";
        cerr << now.obs_cost_ore << " " << now.obs_cost_clay << " ";
        cerr << now.geode_cost_ore << " " << now.geode_cost_obs << "\n";

        vt v;
        robots r;
        r.ores = 1;
        threads.pb(thread(go2, ind, now, v, r, 32));
        ++ind;
    }
    FOR(i,threads.size()) {
        threads[i].join();
    }
    cout << res;
    return 0;
}


//too low - 552