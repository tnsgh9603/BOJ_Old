#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int temp[1001], arr[1001];
vector <int> vec[1001];
vector <int> ans;
queue <int> q;
int main() {
    int N, M, k;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> temp[i];
        }
        for (int i = 0; i < k - 1; i++) {
            int a = temp[i];
            int b = temp[i + 1];
            vec[a].push_back(b);
            arr[b]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!arr[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        ans.push_back(now);
        for (int i = 0; i < vec[now].size(); i++) {
            int next = vec[now][i];
            if (--arr[next] == 0) {
                q.push(next);
            }
        }
    }
    if (ans.size() != N) {
        cout << "0";
    }
    else {
        for (int i = 0; i < ans.size();i++) {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}
