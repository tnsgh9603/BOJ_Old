#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int arr[32001];
vector <int> vec[32001];
priority_queue <int, vector<int>, greater<int>> q;
int main() {
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        arr[b]++;
    }
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        int here = q.top();
        q.pop();
        cout << here << " ";
        for (int i = 0; i < vec[here].size();i++) {
            int there = vec[here][i];
            if (--arr[there] == 0) {
                q.push(there);
            }
        }
    }
    return 0;
}