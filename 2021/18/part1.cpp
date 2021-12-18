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

bool check(int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

string scan(stringstream &ss, char delim) {
    string v;
    getline(ss, v, delim);
    return v;
}

int scan_int(stringstream &ss, char delim) {
    return atoi(scan(ss, delim).c_str());
}

vector<string> scan_strings(stringstream &ss, char delim) {
    string v;
    vector<string> res;
    while (getline(ss, v, delim)) {
        res.pb(v);
    }
    return res;
}

vector<ll> scan_ints(stringstream &ss, char delim) {
    string v;
    vector<ll> res;
    while (getline(ss, v, delim)) {
        res.pb(atol(v.c_str()));
    }
    return res;
}

struct pt {
    pt *left = nullptr;
    pt *right = nullptr;
    pt *par = nullptr;
    ll val = -1;

    pt(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
        par = nullptr;
    }
};

pt *parse(string &s) {
    vector<pt *> values;
    FOR(i, s.size()) {
        if (s[i] == ',') {
            continue;
        }
        if (s[i] == '[') {
            continue;
        }
        if (s[i] == ']') {
            pt *y = values.back();
            values.pop_back();
            pt *x = values.back();
            values.pop_back();
            pt *now = new pt(-1);
            now->left = x;
            now->right = y;
            now->left->par = now;
            now->right->par = now;
            values.pb(now);
            continue;
        }
        pt *now = new pt(s[i] - '0');
        values.pb(now);
    }
    return values[0];
}

vector<pair<pt*,int>> g;
void go(pt *v, int lvl = 0) {
    if (v->left == nullptr) {
        g.pb(mp(v,lvl));
        return;
    }
    go(v->left,lvl + 1);
    go(v->right, lvl + 1);
}

void print(pt *v) {
    if (v->left == nullptr) {
        cout << v->val;
        return;
    }
    cout << "[";
    print(v->left);
    cout << ",";
    print(v->right);
    cout << "]";
}

ll sum(pt *v) {
    if (v->left == nullptr) {
        return v->val;
    }
    return sum(v->left) * 3 + sum(v->right) * 2;
}


int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string v;
    vector<string> s;
    while (cin >> v) {
        s.pb(v);
    }
    int n = s.size();
    pt *tree = parse(s[0]);
    vector<char> res;
    REP(tt, 1, n) {
        pt *next_right = parse(s[tt]);
        pt *now = new pt(-1);
        now->left = tree;
        now->right = next_right;
        now->left->par = now;
        now->right->par = now;
        tree = now;
        bool found = true;
        while(found) {
            found = false;
            g.clear();
            go(tree);
            /*print(tree);
            cout << "\n";*/
            FOR(i, g.size()) {
                if (g[i].second >= 5 && g[i].first->left == nullptr) {
                    int j = i - 1;
                    while (j >= 0) {
                        pt *p = g[j].first;
                        if (p->val != -1) {
                            p->val += g[i].first->val;
                            break;
                        }
                        --j;
                    }
                    j = i + 2;
                    while (j < g.size()) {
                        pt *p = g[j].first;
                        if (p->val != -1) {
                            p->val += g[i + 1].first->val;
                            break;
                        }
                        ++j;
                    }
                    pt *par = g[i].first->par;
                    par->left = nullptr;
                    par->right = nullptr;
                    par->val = 0;
                    found = true;
                    break;
                }
            }
            if (found) {
                continue;
            }
            FOR(i,g.size()) {
                if (g[i].first->val >= 10) {
                    pt *cur = g[i].first;
                    pt *left = new pt(cur->val / 2);
                    pt *right = new pt((cur->val + 1) / 2);
                    cur->left = left;
                    cur->right = right;
                    left->par = cur;
                    right->par = cur;
                    found = true;
                    break;
                }
            }
        }
        /*cout << "----\n";
        print(tree);
        cout << "\n";*/
        cout.flush();
    }
    /*g.clear();
    go(tree);
    FOR(i,g.size()) {
        cout << g[i].first->val << " ";
    }*/
    cout << sum(tree);
    return 0;
}
