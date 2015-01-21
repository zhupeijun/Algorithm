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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct node {
    int id;
    int child[26];

    void init() {
        memset(child, 0, sizeof(child));
        id = -1;
    }
} tr[1000005];

int root, tot;

void init() {
    root = tot = 0;
    tr[root].init();
}

void insert(string s, int id) {
    int p = root, n = s.size();
    for(int k = 0; k < n; k++) {
        int index = s[k] - 'a';
        if(!tr[p].child[index]) {
            tr[++tot].init();
            tr[p].child[index] = tot;
        }
        p = tr[p].child[index];
        if(tr[p].id == -1) tr[p].id = id;
    }
}

int find(string s, int id) {
    int p = root, ans = 0, n = s.size();
    for(int k = 0; k < n; k++) {
        int index = s[k] - 'a';
        p = tr[p].child[index];
        ans ++;
        if(tr[p].id == id) return ans;
    }
    return ans;
}

int main() {
    freopen("autocomplete.txt", "r", stdin);
    freopen("autocomplete_out.txt", "w", stdout);
    int ci, cn;
    cin >> cn;
    for(ci = 1; ci <= cn; ci++) {
        init();
        int n;
        cin >> n;
        vector<string> vs;
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            vs.push_back(s);
            insert(s, i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int res = find(vs[i], i);
            ans += res;
        }
        cout << "Case #" << ci << ": " << ans << endl;
    }
    return 0;
}

