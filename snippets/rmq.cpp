#include <bits/stdc++.h>

using namespace std;

struct RMQ {
    int n;
    vector<int> dat;

    RMQ(int n_) {
        n = 1;
        while (n < n_) n*= 2;
        dat.resize(n*2-1, 0);
    }
    
    void update(int k, int a) {
        k += n-1;
        dat[k] = a;
        while (k > 0) {
            k = (k-1)/2;
            dat[k] = max(dat[k*2+1], dat[k*2+2]);
        }
    }
   
    int query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return dat[k];
        else {
            int m = (l+r)/2;
            int lv = query(a, b, k*2+1, l, m);
            int rv = query(a, b, k*2+2, m, r);
            return max(lv, rv);
        }
    }
    
    int query(int a, int b) { 
        return query(a, b, 0, 0, n); 
    }
};

int main() {
    RMQ rmq(5);
    rmq.update(0, 1);
    cout << rmq.query(0, 5) << endl;
}