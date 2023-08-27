#include <bits/stdc++.h>

using namespace std;

vector<int> keys = {
    319,
    680,
    180,
    690,
    129,
    620,
    762,
    689,
    762,
    318,
    368,
    710,
    720,
    710,
    629,
    168,
    160,
    689,
    716,
    731,
    736,
    729,
    316,
    729,
    729,
    710,
    769,
    290,
    719,
    680,
    318,
    389,
    162,
    289,
    162,
    718,
    729,
    319,
    790,
    680,
    890,
    362,
    319,
    760,
    316,
    729,
    380,
    319,
    728,
    716
};

int main() {
    // 73162890
    vector<int> ans = {7,3,1,6,2,8,9,0};

    for (int v : keys) {
        vector<int> p(3, 999);
        vector<int> a(3);
        a[2] = v%10; v /= 10; 
        a[1] = v%10; v /= 10;
        a[0] = v;

        for (int j = 0; j < ans.size(); ++j) {
            for (int k = 0; k < 3; ++k) {
                if (ans[j] == a[k]) {
                    p[k] = j;
                }
            }
        }

        for (int k = 1; k < 3; ++k) {
            if (p[k-1] > p[k]) {
                cout << "Bad at: " << v << endl;
                return 0;
            }
        }

    }
    
    cout << "All Good." << endl;
    return 0;
}