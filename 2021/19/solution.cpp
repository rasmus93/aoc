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

vector<ll> scan_longs(stringstream &ss, char delim) {
    string v;
    vector<ll> res;
    while (getline(ss, v, delim)) {
        res.pb(atol(v.c_str()));
    }
    return res;
}

VI scan_ints(stringstream &ss, char delim) {
    string v;
    VI res;
    while (getline(ss, v, delim)) {
        res.pb(atoi(v.c_str()));
    }
    return res;
}

vector<VPII> precalc() {
    VI perm(3);
    FOR(k, 3) {
        perm[k] = k;
    }
    vector<VPII> perms;
    do {
        FOR(i, 8) {
            VPII now(3);
            int dj = i;
            FOR(j, 3) {
                now[j] = mp(perm[j], (dj & 1) ? 1 : -1);
                dj >>= 1;
            }
            perms.pb(now);
        }
    } while (next_permutation(perm.begin(), perm.end()));
    return perms;
}

VVI get_now(vector<VVI> &scanners, int index) {
    int n = scanners[index].size();
    VVI now(n, VI(3));
    FOR(k, n) {
        FOR(l, 3) {
            now[k][l] = scanners[index][k][l];
        }
    }
    return now;
}

VVI get_beacons(vector<VVI> &scanners, VPII &perms, VI &diffs, int index) {
    int n = scanners[index].size();
    VVI now = get_now(scanners, index);
    VVI result(n, VI(3));
    FOR(j, n) {
        FOR(k, 3) {
            result[j][k] = now[j][perms[k].first] * perms[k].second - diffs[k];
        }
    }
    return result;
}

int get_equal_beacons(VVI &x, VVI &y, VI &diff) {
    int eq = 0;
    FOR(k1, x.size()) {
        FOR(l1, y.size()) {
            int cnt = 0;
            FOR(m, 3) {
                cnt += y[l1][m] - x[k1][m] == diff[m] ? 1 : 0;
            }
            if (cnt == 3) {
                ++eq;
                break;
            }
        }
    }
    return eq;
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    string s;
    vector<VVI> scanners;
    VVI now;
    while (cin >> s) {
        if (s == "---") {
            cin >> s >> s >> s;
            if (!now.empty()) {
                scanners.pb(now);
            }
            now.clear();
            continue;
        }
        stringstream ss(s);
        VI values = scan_ints(ss, ',');
        now.pb(values);
    }
    scanners.pb(now);
    now.clear();
    int n = scanners.size();

    queue<int> q;
    VB used(n);
    VVI diffs(n);
    VI perm_index(n);
    vector<VPII> perms = precalc();

    used[0] = true;
    q.push(0);
    VI st(3, 0);
    diffs[0] = st;
    perm_index[0] = 7;


    while (!q.empty()) {
        int i = q.front();
        cerr << i << "\n";
        q.pop();
        VVI x = get_beacons(scanners, perms[perm_index[i]], diffs[i], i);
        int szx = scanners[i].size();

        FOR(j, n) {
            if (used[j]) {
                continue;
            }
            int szy = scanners[j].size();
            VVI now = get_now(scanners, j);
            VVI y(szy, VI(3));

            VI res_diff(3);
            VI now_diff(3);
            int found_perm_index = -1;
            FOR(p, perms.size()) {
                FOR(k, szy) {
                    FOR(l, 3) {
                        y[k][l] = now[k][perms[p][l].first] * perms[p][l].second;
                    }
                }

                FOR(k, szx) {
                    FOR(l, szy) {
                        FOR(m, 3) {
                            now_diff[m] = y[l][m] - x[k][m];
                        }

                        if (get_equal_beacons(x, y, now_diff) >= 12) {
                            FOR(xz, 3) {
                                res_diff[xz] = now_diff[xz];
                            }
                            found_perm_index = p;
                            break;
                        }
                    }
                    if (found_perm_index != -1) {
                        break;
                    }
                }
                if (found_perm_index != -1) {
                    break;
                }
            }

            if (found_perm_index != -1) {
                diffs[j] = res_diff;
                perm_index[j] = found_perm_index;
                used[j] = true;
                q.push(j);
            }
        }
    }

    vector<pair<int, PII>> beacons;
    FOR(i, n) {
        VVI x = get_beacons(scanners, perms[perm_index[i]], diffs[i], i);
        FOR(j, x.size()) {
            beacons.pb(mp(x[j][0], mp(x[j][1], x[j][2])));
        }

    }
    sort(beacons.begin(), beacons.end());
    beacons.erase(unique(beacons.begin(), beacons.end()), beacons.end());
    int dist = 0;
    FOR(i, n) {
        REP(j, i + 1, n) {
            int now = 0;
            FOR(k, 3) {
                now += abs(diffs[i][k] - diffs[j][k]);
            }
            dist = max(dist, now);
        }
    }
    cout << beacons.size() << " " << dist;
    return 0;
}
