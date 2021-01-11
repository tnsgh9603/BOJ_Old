#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    //vector<int> -> p
    struct p {
        int x, y, idx;
        bool operator < (const p& p) const {
            return x < p.x;
        }
    };
    vector<p> v;
    for (int i = 0; i < nodeinfo.size(); i++) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        v.push_back({ x, y, i + 1 });
    }
    sort(v.begin(), v.end());

    //tree traversal
    vector<int> preorder, postorder;
    function<void(int, int)> dfs = [&](int s, int e) -> void {
        int cur = s;
        for (int i = s; i <= e; i++) {
            if (v[i].y > v[cur].y) cur = i;
        }
        preorder.push_back(v[cur].idx);
        if (cur != s) dfs(s, cur - 1);
        if (cur != e) dfs(cur + 1, e);
        postorder.push_back(v[cur].idx);
    };
    dfs(0, v.size() - 1);
    return vector<vector<int>>{preorder, postorder};
}