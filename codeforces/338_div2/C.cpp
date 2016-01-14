#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2105;

#define CL(a, b) memset(a, b, sizeof(a))

int f1[N][N], f2[N][N];

int main() {
	string s, t;
	cin >> s >> t;
	int sn = s.size(), tn = t.size();
	CL(f1, 0); CL(f2, 0);
	for (int i = tn - 1; i >= 0; --i) {
		for (int j = sn - 1; j >= 0; --j)
			if (s[j] == t[i]) f1[i][j] = max(f1[i][j], f1[i + 1][j + 1] + 1);
	}
	for (int i = tn - 1; i >= 0; --i) {
		for (int j = 0; j < sn; ++j) {
			if (s[j] == t[i]) f2[i][j] = max(f2[i][j], (j == 0 ? 0 : f2[i + 1][j - 1]) + 1);
		}
	}
	int cur = 0, cnt = 0;
	vector<pair<int,int>> ans;
	while (cur < tn) {
		int max_length = 0, l, r;
		for (int j = 0; j < sn; ++j) {
			if (max_length < f1[cur][j]) {
				l = j; r = j + f1[cur][j] - 1;
				max_length = f1[cur][j];
			}
			if (max_length < f2[cur][j]) {
				l = j; r = j - f2[cur][j] + 1;
				max_length = f2[cur][j];
			}
		}
		if (max_length == 0) { cnt = -1; ans.clear();  break; }
		ans.push_back(make_pair(l, r));
		cur = cur + max_length;
		++cnt;
	}
	cout << cnt << endl;
	int m = ans.size();
	for (int i = 0; i < m; ++i) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}
	return 0;
}
