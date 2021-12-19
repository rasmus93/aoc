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
    int x;
    int y;
    int z;

    pt(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};


vector<VPII> precalc() {
    int dx[2] = {-1, 1};
    VI perm(3);
    FOR(k, 3) {
        perm[k] = k;
    }
    vector<VPII> perms;
    do {

        FOR(i, 2) {
            FOR(j, 2) {
                FOR(k, 2) {
                    VPII now(3);
                    FOR(l, 3) {
                        int v;
                        if (l == 0) {
                            v = dx[i];
                        }
                        if (l == 1) {
                            v = dx[j];
                        }
                        if (l == 2) {
                            v = dx[k];
                        }
                        now[l] = mp(perm[l], v);
                    }
                    perms.pb(now);
                }
            }
        }
    } while (next_permutation(perm.begin(), perm.end()));

    /*FOR(i,perms.size()) {
        FOR(j,perms[i].size()) {
            cout << perms[i][j].first << "(" << perms[i][j].second << "), ";
        }
        cout << "\n";
    }*/
    return perms;
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    vector<VPII> perms = precalc();

    string s;
    vector<vector<pt>> scanners;
    vector<pt> now;
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
        vector<ll> values = scan_ints(ss, ',');
        now.pb(pt(values[0], values[1], values[2]));
    }
    scanners.pb(now);
    now.clear();
    int n = scanners.size();

    queue<int> q;
    VB used(n);
    VVI diffs(n);
    VI perm_index(n);

    used[0] = true;
    q.push(0);
    VI st(3,0);
    diffs[0] = st;
    perm_index[0] = 7;


    while (!q.empty()) {
        int i = q.front();
        cerr << i << "\n";
        q.pop();
        int szx = scanners[i].size();
        VVI now(szx, VI(3));
        FOR(k, szx) {
            now[k][0] = scanners[i][k].x;
            now[k][1] = scanners[i][k].y;
            now[k][2] = scanners[i][k].z;
        }
        VVI x(szx, VI(3));
        FOR(k, szx) {
            FOR(l, 3) {
                x[k][l] = now[k][perms[perm_index[i]][l].first] * perms[perm_index[i]][l].second
                        - diffs[i][l];
                //x[k][l] = now[k][perms[perm_index[i]][l].first] * perms[perm_index[i]][l].second;
                //x[k][l] = now[k][l];
            }
        }

        REP(j,0,n) {
            if (used[j]) {
                continue;
            }
            int szy = scanners[j].size();
            VVI now(szy, VI(3));
            FOR(k, szy) {
                now[k][0] = scanners[j][k].x;
                now[k][1] = scanners[j][k].y;
                now[k][2] = scanners[j][k].z;
            }
            VVI y(szy, VI(3));
            FOR(k, szy) {
                FOR(l, 3) {
                    y[k][l] = now[k][perms[perm_index[i]][l].first] * perms[perm_index[i]][l].second
                              - diffs[i][l];
                }
            }

            VI res_diff(3);
            int res_perm = 0;
            bool found = false;
            FOR(p, perms.size()) {
                FOR(k, szy) {
                    FOR(l, 3) {
                        y[k][l] = now[k][perms[p][l].first] * perms[p][l].second;
                    }
                }

                FOR(k, szx) {
                    FOR(l, szy) {
                        VI diff(3);
                        FOR(m, 3) {
                            diff[m] = y[l][m] - x[k][m];
                        }
                        int eq = 0;
                        FOR(k1, szx) {
                            FOR(l1, szy) {
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
                        if (eq >= 12) {
                            FOR(xz,3) {
                                res_diff[xz] = diff[xz];// * perms[p][xz].second;
                            }
                            res_perm = p;
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }

            if (found) {
                diffs[j] = res_diff;
                perm_index[j] = res_perm;
                used[j] = true;
                q.push(j);
            }
        }
    }

    vector<pair<int,PII>> beacons;
    FOR(i,n) {
        //cout << i << "----\n";
        int szx = scanners[i].size();
        VVI now(szx, VI(3));
        FOR(k, szx) {
            now[k][0] = scanners[i][k].x;
            now[k][1] = scanners[i][k].y;
            now[k][2] = scanners[i][k].z;
        }
        VVI x(szx, VI(3));
        FOR(k, szx) {
            FOR(l, 3) {
                x[k][l] = now[k][perms[perm_index[i]][l].first] * perms[perm_index[i]][l].second
                          - diffs[i][l];
                //cout << x[k][l] << ",";
            }
            //cout << "\n";
            beacons.pb(mp(x[k][0],mp(x[k][1],x[k][2])));
        }

    }
    sort(beacons.begin(), beacons.end());
    beacons.erase(unique(beacons.begin(), beacons.end()), beacons.end());
    /*FOR(i,beacons.size()) {
        cout << beacons[i].first << ","
        << beacons[i].second.first << ","
        << beacons[i].second.second <<"\n";
    }*/
    int dist = 0 ;
    FOR(i,n) {
        REP(j,i+1,n) {
            int now = 0;
            FOR(k,3) {
                now += abs(diffs[i][k] - diffs[j][k]);
            }
            dist = max(dist, now);
        }
    }
    cout << beacons.size() << " " << dist;
    return 0;
}
