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

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;
bool is_prime[N];
vector<int> prime;

void get_prime() {
    CL(is_prime, true);
    for(int i = 2; i < N; ++i)
        if (is_prime[i]) {
            for(int j = 2; j * i < N; ++j)
                is_prime[j * i] = false;
            prime.pb(i);
        }
}

int main() {
    get_prime();

    int n;
    scanf("%d", &n);
    set<int> s;
    for(int i = 2; i <= n; ++i) {
        int m = prime.size();
        for(int k = 0; k < m; ++k) {
            int base = prime[k];
            while(i % base == 0) {
                s.insert(base);
                base *= prime[k];
            }
        }
    }
    int sn = s.size();
    printf("%d\n", sn);
    for(auto it = s.begin(); it != s.end(); ++it) {
        printf("%d", *it);
        next(it, 1) == s.end() ? printf("\n") : printf(" ");
    }
    return 0;
}

