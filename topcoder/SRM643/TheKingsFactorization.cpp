#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;

const int N = 1000005;

vll prime_set;
bool is_prime[N];

class TheKingsFactorization {
public:
    void get_prime() {
        memset(is_prime, true, sizeof(is_prime));
        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i < N; i++)
            if(is_prime[i]) {
                for(int j = 2; j * i < N; j++)
                    is_prime[i * j] = false;
                prime_set.push_back(i);
            }
    }
    vll getVector(ll N, vll primes) {
        get_prime();
        ll x = N;
        int n = primes.size();
        for(int i = 0; i < n; i++)
            x /= primes[i];
        int m = prime_set.size();
        for(int i = 0; i < m; i++) {
            while(x % prime_set[i] == 0) {
                primes.push_back(prime_set[i]);
                x /= prime_set[i];
            }
            if(x == 1) break;
        }
        if(x != 1) primes.push_back(x);
        sort(primes.begin(), primes.end());
        return primes;
    }
};