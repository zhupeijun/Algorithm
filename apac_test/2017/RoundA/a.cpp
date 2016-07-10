#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>
#include <list>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pc __builtin_popcount
#define mp make_pair
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define REP(i, b) FOR(i, 0, b)

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int N;
    scanf("%d\n", &N);
    vector<string> names;
    for (int i = 0; i < N; ++i) {
        string name;
        getline(cin, name);
        names.pb(name);
    }

    vector<pair<size_t, string>> result;
    for (int i = 0; i < N; ++i) {
        set<char> S;
        string s = names.at(i);
        int m = s.size();
        for (int j = 0; j < m; ++j) {
            if (s[j] != ' ') {
                S.insert(s[j]);
            }
        }
        result.pb(make_pair(S.size(), s));
    }

    sort(result.begin(), result.end(), [](const pair<size_t, string>& a, const pair<size_t, string> &b){
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    });

    //cout << result.at(0).first << endl;
    printf("%s", result.at(0).second.c_str());
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }
    return 0;
}

