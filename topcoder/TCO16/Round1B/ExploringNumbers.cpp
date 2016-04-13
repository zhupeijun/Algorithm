#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(b))
#define pb push_back

const int N = 1005;

int vis[N];
int is_prime[N];

class ExploringNumbers {
public:
    int sum(int x) {
        int s = 0;
        while (x) {
            int d = x % 10;
            s += d * d;
            x /= 10;
        }
        return s;
    }
    void init() {
        fill(is_prime, is_prime + N, 1);
        is_prime[0] = is_prime[1] = 0;
        for (int i = 2; i < N; ++i) {
            if (is_prime[i]) {
                for (int j = 2; j * i < N; ++j) {
                    is_prime[i * j] = 0; 
                }
            }
        }
    }
     int numberOfSteps(int n) {
         if (n >= 40000) {
             int ok = false;
             for (int i = 2; i < 40000; ++i) {
                 if (n % i == 0) { ok = true; break; }
             }
             if (!ok) return 1;
         }
         init();
        CL(vis, 0);
        for (int i = 0, cur = n; i < n; ++i) {
            if (cur < N) {
                if (cur < N) {
                    if (vis[cur]) return -1;
                    vis[cur] = 1;
                    if (is_prime[cur]) return i + 1;
                }
            }
            cur = sum(cur);
        }
        return -1;
    }
};
