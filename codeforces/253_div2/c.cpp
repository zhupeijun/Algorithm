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

const int N = 200;

vector<string> cards;
map<char, int> M;
int mark[N];

void init() {
    M['R'] = 1;
    M['G'] = 2;
    M['B'] = 3;
    M['Y'] = 4;
    M['W'] = 5;
}

// 0 is color hint, 1 is number hint
void make_mark(int value, int type) {
    int bt = type + 1;
    int i, n = cards.size();
    for(i = 0; i < n; i++) {
        if()
}

bool check() {
    map<string, int> M;
    int n = cards.size(), i;
    for(i = 0; i < n; i++) {
        if(mark[i] != 3) {
            if(M.find(cards[i]) == M.end()) {
                M[cards[i]] = 1;
            } else {
                return false;
            }
        }
    }
    return true;
}


int main() {
    int i, n;
    cin >> n;
    for(i = 0; i < n;i ++) {
        string card;
        cin >> card;
        cards.push_back(card);
    }
    int m = 1 << 8;
    for(k = 0; k < m; k++) {
        int x = k, t = 0;
        while(x) {
            if(x & 1)
                make_mark(t < 4);
            x <<= 1;
        }
    }
    return 0;
}

