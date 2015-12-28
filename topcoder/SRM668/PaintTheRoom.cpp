#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class PaintTheRoom {
public:
    string canPaintEvenly(int R, int C, int K) {
        bool ans;
        if (K == 1) ans = true;
        else if (((R * C) & 1)) ans = false;
        else ans = true;
        return ans ? "Paint" : "Cannot paint";
    }
};
