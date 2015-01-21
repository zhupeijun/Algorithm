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
typedef vector<int> vi;

const int N = 10000005;
const int M = 3200;

int prm[N];
bool is_prime[M];
vi prime;

void get_prime() {
    memset(is_prime, true, sizeof(is_prime));
    for(int i = 2; i < M; i++)
        if(is_prime[i]) {
            for(int j = 2; j * i < M; j++)
                is_prime[i * j] = false;
            prime.push_back(i);
        }
}

void pre_count() {
    get_prime();
    memset(prm, 0, sizeof(prm));
    int pn = prime.size();
    for(int i = 2; i < N; i++) {
        int x = i;
        for(int j = 0; j < pn; j++) {
            if(x % prime[j] == 0) {
                prm[i]++;
                while(x % prime[j] == 0) x /= prime[j];
            }
        }
        if(x != 1) prm[i]++;
    }
}

int main() {
    pre_count();

    freopen("homework_in.txt", "r", stdin);
    freopen("homework_out.txt", "w", stdout);
    int ci, cn;
    scanf("%d", &cn);
    for(ci = 0; ci < cn; ci++) {
        int a, b, k, ans = 0;
        scanf("%d %d %d", &a, &b, &k);
        for(int i = a; i<= b; i++) {
            if(prm[i] == k) ans++;
        }
        printf("Case #%d: %d\n", ci + 1, ans);
    }
    return 0;
}

