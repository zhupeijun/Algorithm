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

char board[10][10];

int main() {
    int w = 0, b = 0;
    for(int i = 0; i < 8; i++) {
        scanf("%s", board[i]);
        for(int j = 0; j < 8; j++) {
            switch(board[i][j]) {
            case 'Q':
                w += 9; break;
            case 'R':
                w += 5; break;
            case 'B':
                w += 3; break;
            case 'N':
                w += 3; break;
            case 'P':
                w += 1; break;
            case 'q':
                b += 9; break;
            case 'r':
                b += 5; break;
            case 'b':
                b += 3; break;
            case 'n':
                b += 3; break;
            case 'p':
                b += 1; break;
            }
        }
    }

    if (w > b) printf("White\n");
    else if(b > w) printf("Black\n");
    else printf("Draw\n");
    return 0;
}

