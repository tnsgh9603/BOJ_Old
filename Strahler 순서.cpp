#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
int k, m, p, s, x, y, in[1001], getmax[1001], cnt[1001], res;
vector<vector<int>> vt;
int main() {
    cin >> k;
    while (k--) {
        vt.clear();
        cin >> s >> m >> p;
        vt.resize(m + 1);
        memset(in, 0, sizeof(in));
        memset(cnt, 0, sizeof(cnt));
        memset(getmax, 0, sizeof(getmax));
        res = 0;
        for (int i = 0; i < p; i++) {
            cin >> x >> y;
            vt[x].push_back(y);
            in[y]++;
        }
        queue <int> q;
        for (int i = 1; i <= m; i++) {
            if (!in[i]) {
                // 강의 근원인 노드의 순서는 1
                getmax[i] = 1;
                q.push(i);
            }
        }
        while (q.size()) {
            int now = q.front();
            q.pop();
            if (cnt[now] > 0) {
                getmax[now]++;
            }
            res = max(getmax[now], res);
            for (int i = 0; i < vt[now].size(); i++) {
                int next = vt[now][i];
                if (getmax[next] < getmax[now]) {
                    getmax[next] = getmax[now];
                    cnt[next] = 0;
                }
                else if (getmax[next] == getmax[now]) {
                    cnt[next]++;
                }
                if (--in[next] == 0) {
                    q.push(next);
                }
            }
        }
        cout << s << " " << res << "\n";
    }
    return 0;
}