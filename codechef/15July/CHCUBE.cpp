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

int list[8][3] = {
    {4, 0, 2},
    {4, 2, 1},
    {4, 1, 3},
    {4, 3, 0},
    {5, 0, 2},
    {5, 2, 1},
    {5, 1, 3},
    {5, 3, 0}
};

int color[6];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 6; i++) {
            char c[10];
            scanf("%s", c);
            if(strcmp(c, "black") == 0)         color[i] = 0;
            else if(strcmp(c, "blue") == 0)     color[i] = 1;
            else if(strcmp(c, "red") == 0)      color[i] = 2;
            else if(strcmp(c, "green") == 0)    color[i] = 3;
            else if(strcmp(c, "yellow") == 0)   color[i] = 4;
            else if(strcmp(c, "orange") == 0)   color[i] = 5;
        }
        bool ok = false;
        for(int j = 0; j < 8; j++) {
            if(color[list[j][0]] == color[list[j][1]] &&
               color[list[j][1]] == color[list[j][2]]) {
                ok = true;
                break;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

