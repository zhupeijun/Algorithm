#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))

class Similars {
public:
	int sim(int x, int y) {
		int xt[10], yt[10];
		CL(xt, 0); CL(yt, 0);
		while(x) { xt[x % 10] = 1; x /= 10; }
		while(y) { yt[y % 10] = 1; y /= 10; }
		int cnt = 0;
		for(int i = 0; i < 10; i++)
			if(xt[i] == 1 && yt[i] == 1) cnt++;
		return cnt;
	}
	int maxsim(int L, int R) {
		int ans = 0;
		for(int i = L; i <= R; i++) {
			int du = R - i;
			if(du > 0) {
				int det = 1;
				for(int j = 0; j < 5; j++) {
					if(i + det <= R) ans = max(ans, sim(i, i + det));
					det *= 10;
				}
			}
			int dd = i - L;
			if(dd > 0) {
				int det = 1;
				for(int i = 0; i < 5; i++) {
					if(i - det >= L) ans = max(ans, sim(i, i - det));
					det *= 10;
				}
			}
			if(i >= 10) {
				int k1 = (i / 10) % 10;
				int k2 = i % 10;
				int k3 = (i / 100 * 10 + k2) * 10 + k1;
				if(i != k3 && k3 >= L && k3 <= R) ans = max(ans, sim(k3, i));
			}
		}
		return ans;
	}
};
