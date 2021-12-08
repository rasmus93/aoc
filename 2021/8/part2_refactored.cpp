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

void find(map<int, string> &number_to_string, vector<string> &s, vector<bool> &used,
          int size, int compareIndex, int fillIndex, int reverse = false) {
    FOR(i, s.size()) {
        if (s[i].size() != size || used[i]) {
            continue;
        }
        string compareString = number_to_string[compareIndex];
        bool ok = true;
        if (!reverse) {
            FOR(j, compareString.size()) {
                if (!contains(s[i], compareString[j])) {
                    ok = false;
                    break;
                }
            }
        } else {
            FOR(j, s[i].size()) {
                if (!contains(compareString, s[i][j])) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            number_to_string[fillIndex] = s[i];
            used[i] = true;
            break;
        }
    }
}

void findLeft(map<int, string> &number_to_string, vector<string> &s, vector<bool> &used, int size, int fillIndex) {
    FOR(i, s.size()) {
        if (s[i].size() != size || used[i]) {
            continue;
        }
        number_to_string[fillIndex] = s[i];
        used[i] = true;
    }
}

void solve(map<int, string> &number_to_string, vector<string> &s) {
    vector<bool> used(10);
    //9
    find(number_to_string, s, used, 6, 4, 9);
    //0
    find(number_to_string, s, used, 6, 7, 0);
    //6
    findLeft(number_to_string, s, used, 6, 6);
    //3
    find(number_to_string, s, used, 5, 7, 3);
    //5
    find(number_to_string, s, used, 5, 6, 5, true);
    //6
    findLeft(number_to_string, s, used, 5, 2);
    if (number_to_string.size() != 10) {
        throw 1;
    }
}

map<int,int> get_known() {
    map<int,int> known;
    known[2] = 1;
    known[4] = 4;
    known[3] = 7;
    known[7] = 8;
    return known;
}

int main() {
    // g++ main.cpp -std=c++17 -pthread -O3 -o Solution
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    string numbers, output;
    ll res = 0;
    map<int,int> known = get_known();
    while (getline(cin, numbers)) {
        map<int, string> number_to_string;
        stringstream ss_numbers(numbers);
        string current;
        vector<string> s;
        while (getline(ss_numbers, current, ' ')) {
            if (current == "|") {
                continue;
            }
            int n = current.size();
            sort(current.begin(), current.end());
            if (known.count(n) != 0) {
                number_to_string[known[n]] = current;
            }
            s.pb(current);
        }
        solve(number_to_string, s);
        map<string, int> string_to_number;
        FOR(i, 10) {
            string_to_number[number_to_string[i]] = i;
        }

        getline(cin, output);
        stringstream ss_output(output);
        ll now = 0;
        while (getline(ss_output, current, ' ')) {
            sort(current.begin(), current.end());
            now *= 10;
            now += string_to_number[current];
        }
        res += now;
    }
    cout << res;
    return 0;
}
