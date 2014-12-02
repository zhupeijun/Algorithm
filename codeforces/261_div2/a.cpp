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

typedef long long LL;

using namespace std;

int main() {
    int x1, y1, x2, y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int d = abs(x1 - x2);
    if(d == 0) d = abs(y1 - y2);

    if(x1 - x2 == d && y1 - y2 == -d) //left top
        printf("%d %d %d %d\n", x2, y1, x1, y2);
    else if(x1 == x2 && y1 - y2 == -d) //top
        printf("%d %d %d %d\n", x1 - d, y1, x2 - d, y2);
    else if(x1 - x2 == -d && y1 - y2 == -d) // right top
        printf("%d %d %d %d\n", x1, y2, x2, y1);
    else if(x1 - x2 == d && y1 == y2) //left
        printf("%d %d %d %d\n", x2, y2 + d, x1, y1 + d);
    else if(x1 - x2 == -d && y1 == y2) // right
        printf("%d %d %d %d\n", x1, y1 + d, x2, y2 + d);
    else if(x1 - x2 == d && y1 - y2 == d) // left bottom
        printf("%d %d %d %d\n", x2, y1, x1, y2);
    else if(x1 == x2 && y1 - y2 == d) // bottom
        printf("%d %d %d %d\n", x1 + d, y1, x2 + d, y2);
    else if(x1 - x2 == -d && y1 - y2 == d) // right bottom
        printf("%d %d %d %d\n", x1, y2, x2, y1);
    else printf("-1\n");

    return 0;
}


