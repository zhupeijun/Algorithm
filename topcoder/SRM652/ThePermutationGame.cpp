#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

const int M = 100005;
const int MOD = 1000000007;
bool is_prime[M];

class ThePermutationGame {
public:
    void get_prime() {
        memset(is_prime, true, sizeof(is_prime));
        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i < M;i++)
            if(is_prime[i])
                for(int j = 2; j * i < M; j++)
                    is_prime[i * j] = false;
    }
    int findMin(int N) {
        get_prime();
        ll ans = 1;
        for(int i = 2; i <= N; i++) {
            if(!is_prime[i]) continue;
            ll b = i;
            while(b * i <= N) b *= i;
            ans = (ans * b) % MOD;
        }
        return ans;
    }
};