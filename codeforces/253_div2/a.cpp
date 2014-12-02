#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int exist[26];

int main() {
    string s;
    getline(cin, s);
    int i, n = s.size(), ans = 0;
    memset(exist, 0, sizeof(exist));
    for(i = 0; i < n; i++) {
        char c = s[i];
        if(c >= 'a' && c <= 'z') {
            int k = c - 'a';
            if(exist[k] == 0) {
                exist[k] = 1; 
                ans ++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
