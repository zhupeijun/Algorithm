#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const int MN = 13;

char MM[MN][5] = {
    "",
    "Jan", "Feb", "Mar",
    "Apr", "May", "Jun",
    "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"
};

int DS[MN] = {
    0,
    31, 28, 31,
    30, 31, 30,
    31, 31, 30,
    31, 30, 31
};


struct OD {
    int h, c;
    OD(int h, int c) {
        this->h = h;
        this->c = c;
    }
};

struct Q {
    ll p, s, d;
    Q(int p, int s, int d) {
        this->p = p;
        this->s = s;
        this->d = d;
    }

    bool operator < (const Q& o) const {
       ll md = max(d, o.d);
       return p+s*(md-d) > o.p+o.s*(md-o.d);
    }
};

int getm(char *month) {
    for(int i = 0; i < MN; ++i) {
        if (strcmp(month, MM[i]) == 0) {
            return i;
        }
    }
    return -1;
}

bool is29(int year) {
    return year % 400 == 0 || (year%4 == 0 && year% 100 != 0);
}

int cal(int year, int month, int day, int hour) {
    int sy = 2000, sm = 1, sd = 1, sh = 0;
    int ans = 0; 
    while (true) {
        if (sy < year) {
            int days = is29(sy) ? 366 : 365;
            ans += days * 24;
            ++sy;
        } else if (sm < month) {
            int days = DS[sm];
            if (sm == 2 && is29(sy)) ++days;
            ans += days * 24;
            ++sm;
        } else if (sd < day) {
            ans += 24;
            ++sd;
        } else if (sh < hour) {
            ++ans;
            ++sh;
        } else {
            break;
        }
    }
    return ans;
}

bool solve() {
    int N, M;
    cin >> N >> M;
    if (N == 0 && M == 0) return false;
    vector<OD> orders;
    for (int i = 0; i < N; ++i) {
        char ms[5];
        int month, day, year, hour, order;
        cin >> ms >> day >> year >> hour >> order;
        month = getm(ms);
        int t = cal(year, month, day, hour);
        orders.push_back(OD(t, order)); 
    }

    int T, S;
    cin >> T >> S;

    vector<int> P(M);
    for (int i = 0; i < M; ++i) {
        cin >> P[i];
    }

    ll cost = 0;
    priority_queue<Q> q;
    for (int i = 0, j = 0; i < M && j < N; ++i) {
        q.push(Q(P[i], S, i));
        if (orders[j].h > i) continue;
        while (!q.empty() && i - q.top().d > T) {
            q.pop();
        }
        Q t = q.top();
        while (j < N && orders[j].h == i) {
            cost += (t.p+t.s*(i-t.d)) * orders[j].c;
            ++j;
        }
    }
    cout << cost << endl;
    return true;
}

int main() {
    while (solve());
    return 0;
}
