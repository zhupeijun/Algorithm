#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

class VampireTree {
public:
    int maxDistance(vector <int> num) {
        int sum = accumulate(num.begin(), num.end(), 0), n = num.size(), ans = -1;
        if (sum != n * 2 - 2) return ans;
        for (int i = 0; i < n; ++i) {
            int dist = num[i] > 1;
            for (int j = 0; j < n; ++j) dist += (j != i && num[j] > 1);
            ans = max(ans, dist + 1);
        }
        return ans;
    }
};
