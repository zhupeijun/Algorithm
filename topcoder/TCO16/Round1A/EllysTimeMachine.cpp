#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class EllysTimeMachine {
public:
    string getTime(string time) {
        vector<string> H = {"12", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11"};
        vector<string> M = {"00", "05", "10", "15", "20", "25", "30", "35", "40", "45", "50", "55"}; 
        string h = time.substr(0, 2);
        string m = time.substr(3, 2);
        int n = H.size();
        string rh = "", rm = "";
        for (int i = 0; i < n; ++i) if (H[i] == h) { rm = M[i]; break; }
        for (int i = 0; i < n; ++i) if (M[i] == m) { rh = H[i]; break; }
        return rh + ":" + rm;
    }
};
