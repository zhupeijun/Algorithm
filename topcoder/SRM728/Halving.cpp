#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <climits>

using namespace std;

typedef pair<int,int> pii;

#define mp make_pair

class Halving {
public:
    int minSteps(vector <int> a) {
        int n = a.size();
        map<int, pii> M;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            queue<pii> q; q.push(mp(x, 0));
            set<int> S; S.insert(x);
            M[x].first += 1;
            while (!q.empty()) {
                pii t = q.front(); q.pop();
                int v = t.first;
                int c = t.second;
                if (v < 2) continue;
                if (v & 1) {
                    int y1 = (v + 1) / 2;
                    int y2 = (v - 1) / 2;
                    if (S.find(y1) == S.end()) {
                        q.push(mp(y1, c + 1));
                        M[y1].first += 1;
                        M[y1].second += (c + 1);
                        S.insert(y1);
                    }
                    if (S.find(y2) == S.end()) {
                        q.push(mp(y2, c + 1));
                        M[y2].first += 1;
                        M[y2].second += (c + 1);
                        S.insert(y2);
                    }
                } else {
                    int y = v / 2;
                    if (S.find(y) == S.end()) {
                        q.push(mp(y, c + 1));
                        M[y].first += 1;
                        M[y].second += (c + 1);
                        S.insert(y);
                    }
                }
            }
        }

        int min_step = INT_MAX;
        for (const auto& it : M) {
            if (it.second.first == n && it.second.second < min_step) {
                min_step = it.second.second;
            }
        }
        return min_step;
    }
};
