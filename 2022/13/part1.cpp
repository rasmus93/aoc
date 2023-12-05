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
//VI values = scan_ints(ss, ',');
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
    vector<pt *> next;
    int value = -1;
};

pt *go(string x) {
    int i = 0;
    pt *root = new pt();
    vector<pt *> now;
    now.pb(root);
    string value = "";
    while (i < x.size()) {
        if (x[i] == '[') {
            pt *next = new pt();
            now.pb(next);
            ++i;
            continue;
        }
        if (x[i] == ']') {
            if (!value.empty()) {
                pt *v = new pt();
                v->value = atoi(value.c_str());
                now.back()->next.pb(v);
                value = "";
            }

            now[now.size() - 2]->next.pb(now.back());
            now.pop_back();
            ++i;
            continue;
        }
        if (x[i] == ',') {
            if (!value.empty()) {
                pt *v = new pt();
                v->value = atoi(value.c_str());
                now.back()->next.pb(v);
                value = "";
            }

            ++i;
            continue;
        }
        value += x[i];
        ++i;
    }
    return root;
}

int comp(const pt *x, const pt *y) {
    // both integers
    if (x->value != -1 && y->value != -1) {
        //return x->value < y->value;
        return x->value < y->value
               ? -1
               : (x->value > y->value ? 1 : 0);
    }
    if (x->value == -1 && y->value == -1) {
        FOR(i, min(x->next.size(), y->next.size())) {
            if (comp(x->next[i], y->next[i]) == 0) {
                continue;
            }
            return comp(x->next[i], y->next[i]);
        }
        return x->next.size() < y->next.size()
               ? -1
               : (x->next.size() > y->next.size() ? 1 : 0);
    }
    pt *v = new pt();
    if (x->value != -1) {
        pt *next = new pt();
        next->value = x->value;
        v->next.pb(next);
        return comp(v, y);
    } else {
        pt *next = new pt();
        next->value = y->value;
        v->next.pb(next);
        return comp(x,v);
    }
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
    int res = 0;
    int ind = 1;
    vector<pt *> all;
    while (cin >> x >> y) {
        pt *x_root = go(x);
        pt *y_root = go(y);
        if (comp(x_root, y_root) < 0) {
            res += ind;
        }
        all.pb(x_root);
        all.pb(y_root);
        ++ind;
    }
    //sort(all.begin(), all.end(), comp);
    cout << res;
    return 0;
}