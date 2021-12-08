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

vector<ll> go(vector<ll> &a) {
    int n = a.size();
    vector<ll> res(2000);
    FOR(i,2000) {
        ll now = 0;
        FOR(j, n) {
            ll v = abs(a[j] - i);
            now += v;//v * (v + 1) / 2;
        }
        res[i] = now;
    }
    return res;
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string str;
    getline(cin, str);
    stringstream ss(str);
    string v;
    vector<ll> a;
    while (getline(ss, v, ',')) {
        a.pb(atoi(v.c_str()));
    }
    sort(a.begin(), a.end());
    vector<ll> b = go(a);
    int n = a.size();
    ll now = 0;
    ll prev = a[0];
    ll next = 0;
    FOR(i, n) {
        ll v = abs(a[i] - a[0]);
        now += v * (v + 1) / 2;
        next += a[i];
    }
    ll res = b[0];
    next -= a[0];
    REP(i, 1, n) {
        ll dist = a[i] - a[i - 1];
        now += i * dist * a[i] - dist * prev - i * dist * (dist - 1) / 2;
        now -= dist * next - (n - i) * dist * a[i - 1] - (n - i) * dist * (dist - 1) / 2;
        if (b[i] != now) {
            cout << i << " " << b[i] << " " << now << "\n";
        }
        res = min(res, now);
        next -= a[i];
        prev += a[i];
    }
    cout << res;
    //102245489
    return 0;
}
