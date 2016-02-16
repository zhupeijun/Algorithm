#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <functional>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

#define MP(a, b) make_pair(a, b)

class FleetFunding {
public:
    bool good(int m, const vector<int>& k, const vector<int>& a, const vector<int>& b, int v) {
        int n = a.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) idx[i] = i;
        sort(idx.begin(), idx.end(), [a](int i, int j) -> bool { return a[i] < a[j]; });
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for (int i = 1, j = 0; i <= m; ++i) {
            while (j < n && a[idx[j]] <= i) { q.push(MP(b[idx[j]], k[idx[j]])); ++j; }
            int cnt = 0;
            while (!q.empty()) {
                pii t = q.top(); q.pop();
                if (t.first < i) continue;
                if (cnt + t.second < v) cnt += t.second;
                else {
                    int need = v - cnt;
                    cnt = v;
                    t.second -= need;
                    q.push(t);
                    break;
                }
            }
            if (cnt < v) return false;
        }
        return true;
    }

    int maxShips(int m, vector <int> k, vector <int> a, vector <int> b) {
        int l = 0, r = 50000005;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (good(m, k, a, b, mid)) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};
