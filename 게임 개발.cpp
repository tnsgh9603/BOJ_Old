#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[501], time[501];
int total_time[501];
vector<int> vec[501];
queue<int> q;
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> time[i];
        while (1) {
            int a; 
            cin >> a;
            if (a == -1) {
                break;
            }
            vec[a].push_back(i);
            arr[i]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 0) {
            q.push(i);
            total_time[i] = time[i];
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < vec[now].size(); i++) {
            int next = vec[now][i];
            total_time[next] = max(total_time[next], total_time[now] + time[next]);
            if (--arr[next] == 0) {
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << total_time[i] << "\n";
    }
    return 0;
}