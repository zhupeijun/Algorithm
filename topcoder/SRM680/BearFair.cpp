#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class BearFair {
public:
    string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
         upTo.push_back(b); quantity.push_back(n);
        int m = upTo.size();
        vector<int> idx(m);
        for (int i = 0; i < m; ++i) idx[i] = i;
        sort(idx.begin(), idx.end(), [upTo](int i, int j){ return upTo[i] < upTo[j]; });
        int max_even = 0, min_even = 0, min_old = 0, max_old = 0;
        for (int i = 0; i < m; ++i) {
            int nums = upTo[idx[i]] - (i == 0 ? 0 : upTo[idx[i - 1]]);
            int qn = quantity[idx[i]] - (i == 0 ? 0 : quantity[idx[i - 1]]);
            if (qn < 0) return "unfair";
            if (nums == 0) continue;
            int nums_even = nums / 2 + ((nums & 1) && !(upTo[idx[i]] & 1));
            int nums_old = nums - nums_even;
            //cout << nums_even << " " << nums_old << endl;
            max_even += min(nums_even, qn);
            min_even += min(nums_even, qn - min(nums_old, qn));
            max_old += min(nums_old, qn);
            min_old += min(nums_old, qn - min(nums_even, qn));
            //cout << min_even << " " << max_even << " " << min_old << " " << max_old << endl;
        }
        int en = n / 2;
        return en >= min_even && en <= max_even && en >= min_old && en <= max_old && min_old + max_even == n ? "fair" : "unfair";
    }
};
