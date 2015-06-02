#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

typedef long long LL;

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int N, M, K, i, j;
        scanf("%d %d %d", &N, &M, &K);
        for(i = 0; i < N; i++) {
            for(j = 0; j < M; j++) {
                printf("A");
                if(j == M - 1) printf("\n");
            }
        }
    }
    return 0;
}

