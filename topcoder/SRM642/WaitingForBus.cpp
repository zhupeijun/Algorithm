#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef vector<int> vi;

const int N = 200005;

double f[N];

class WaitingForBus {
public:
    double whenWillBusArrive(vi time, vi prob, int s) {
        memset(f, 0, sizeof(0));
        f[0] = 1;
        int n = time.size();
        for(int t = 0; t < N; t++) {
            if(t >= s) break;
            if(f[t] > 0) {
                for(int i = 0; i < n; i++)
                    f[t + time[i]] += f[t] * prob[i] * 0.01;
            }
        }
        double ans = 0;
        for(int t = s; t < N; t++) {
            ans += f[t] * (t - s);
        }
        return ans;
    }
};