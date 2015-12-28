#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class TreeAndPathLength3 {
public:
    vector <int> construct(int s) {
        int n = 1;
        while(n * (n + 1) <= s) ++n;
        vector<int> edges;
        for (int i = 1; i <= n; ++i) {
            edges.push_back(0);
            edges.push_back(i);
            edges.push_back(i);
            edges.push_back(i + n);
        }
        int r = s - n * (n - 1);
        for (int i = 0; i < r; ++i) {
            edges.push_back(i + n + n);
            edges.push_back(i + 1 + n + n);
        }
        return edges;
    }
};
