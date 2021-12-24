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

const int inf = -(int) 1e9;

vector<string> ops(255);
vector<string> tos(255);
vector<string> froms(255);
int n = 0;

vector<ll> solve(ll v) {
    string monad = to_string(v);
    vector<ll> a(4);
    int cnt = 0;
    string op, to, from;
    FOR(tt, n) {
        FOR(i, 4) {
            cout << a[i] << " ";
        }
        cout << "; ";
        cout.flush();

        op = ops[tt];
        to = tos[tt];
        from = froms[tt];
        if (op == "inp") {
            a[to[0] - 'w'] = monad[cnt] - '0';
            ++cnt;
            cout << "\n\ncnt=" << cnt - 1 << "\n";
            cout << "inp " << to << " " << a[to[0] - 'w'] << "\n";
            continue;
        }

        cout << op << " " << to << " " << from << "\n";

        ll from_value = 0;
        if (from[0] >= 'w' && from[0] <= 'z') {
            from_value = a[from[0] - 'w'];
        } else {
            from_value = atoi(from.c_str());
        }
        int to_index = to[0] - 'w';
        ll to_value = a[to_index];
        if (op == "mul") {
            a[to_index] = to_value * from_value;
            continue;
        }
        if (op == "add") {
            a[to_index] = to_value + from_value;
            continue;
        }
        if (op == "div") {
            a[to_index] = to_value / from_value;
            continue;
        }
        if (op == "mod") {
            a[to_index] = to_value % from_value;
            continue;
        }
        if (op == "eql") {
            a[to_index] = to_value == from_value ? 1 : 0;
            continue;
        }
    }
    return a;
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string op;
    string from, to;
    while (cin >> op) {
        ops[n] = op;
        if (op == "inp") {
            cin >> to;
            tos[n] = to;
        } else {
            cin >> to >> from;
            tos[n] = to;
            froms[n] = from;
        }
        ++n;
    }
    VI in(14);
    VI z(14);
    z[0] = in[0];
    z[1] = 26 * z[0] + in[1] + 12;
    z[2] = 26 * z[1] + in[2] + 14;
    z[3] = 26 * z[2] + in[3];
    //4
    if (in[4] == in[3] - 2) {
        z[4] = z[2];
    } else {
        z[4] = 26 + z[2] + in[4] + 3;
    }
    z[5] = 26 * z[4] + in[5] + 15;
    z[6] = 26 * z[5] + in[6] + 11;
    //7
    if (in[7] == in[6] - 4) {
        z[7] = z[5];
    } else {
        z[7] = 26 * z[5] + in[7] + 12;
    }
    z[8] = 26 * z[7] + in[8] + 1;
    //9
    if (in[9] == in[8] - 8) {
        z[9] = z[7];
    } else {
        z[9] = 26 * z[7] + in[9] + 12;
    }
    //10
    if (in[9] == in[8] - 8) {
        if (in[7] == in[6] - 4) {
            if (in[10] == in[5] + 6) {
                z[10] = z[4];
            } else {
                z[10] = 26 * z[4] + in[10] + 3;
            }
        } else {
            if (in[10] == in[7] + 3) {
                z[10] = z[5];
            } else {
                z[10] = 26 * z[5] + in[10] + 3;
            }
        }
    } else {
        if (in[10] == in[9] + 3) {
            z[10] = z[7];
        } else {
            z[10] = 26 * z[7] + in[10] + 3;
        }
    }
    //11
    if (in[9] == in[8] - 8) {
        if (in[7] == in[6] - 4) {
            if (in[10] == in[5] + 6) {
                //z[4]
                if (in[4] == in[3] - 2) {
                    if (in[11] == in[2] - 7) {
                        z[11] = z[1];
                    } else {
                        z[11] = 26 * z[1] + in[11] + 10;
                    }
                } else {
                    if (in[11] == in[4] - 4) {
                        z[11] = z[2];
                    } else {
                        z[11] = 26 * z[2] + in[11] + 10;
                    }
                }
            } else {
                //26 * z[4] + in[10] + 3;
                if (in[11] == in[10] - 4) {
                    z[11] = z[4];
                } else {
                    z[11] = 26 * z[4] + in[11] + 10;
                }
            }
        } else {
            if (in[10] == in[7] + 3) {
                //z[5];
                if (in[11] == in[5] - 8) {
                    z[11] = z[4];
                } else {
                    z[11] = 26 * z[4] + in[11] + 10;
                }
            } else {
                //26 * z[5] + in[10] + 3;
                if (in[11] == in[10] - 4) {
                    z[11] = z[5];
                } else {
                    z[11] = 26 * z[5] + in[11] + 10;
                }
            }
        }
    } else {
        if (in[10] == in[9] + 3) {
            z[11] = z[7];
        } else {
            z[11] = 26 * z[7] + in[10] + 3;
        }
    }
    // I give up, I realised that we don't need all combinations
    // because only in one branch z can be 0 ->
    /*
    if (in[9] == in[8] - 8) {
        if (in[7] == in[6] - 4) {
            if (in[10] == in[5] + 6) {
                //z[4]
                if (in[4] == in[3] - 2) {
                    if (in[11] == in[2] - 7) {
                        z[1];
                        //
                        if (in[12] == in[1] + 8) {
                            z[0];
                            if (in[13] == in[0] - 6) {
                                0;
     */
    //     01234567890123
    ll v = 71131151917891ll; // min
    // max = 91297395919993
    cout << solve(v)[3];
    return 0;
}
