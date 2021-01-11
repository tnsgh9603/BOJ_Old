#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector <int> vec[27];
int indegree[27], cost[27], total_time[27], visited[27];
int main() {
    fastio;
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        char s1;
        int temp;
        string s2;
        ss >> s1 >> temp >> s2;
        total_time[s1 - 'A' + 1] = cost[s1 - 'A' + 1] = temp;
        visited[s1 - 'A' + 1] = 1;
        indegree[s1 - 'A' + 1] = s2.size();
        for (int i = 0; i < s2.length(); i++) {
            vec[s2[i] - 'A' + 1].push_back(s1 - 'A' + 1);
        }
    }
    queue <int> q;
    for (int i = 1; i <= 26; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto next : vec[now]) {
            cost[next] = max(cost[next], total_time[next] + cost[now]);
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 26; i++) {
        ans = max(ans, cost[i]);
    }
    cout << ans;
    return 0;
}