#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int N, M;
    cin >> N >> M;
    int temp = M, result = M;
    for (int i = 0; i < N; i++) {
        int in, out;
        cin >> in >> out;
        temp += (in - out);
        // ���� üũ
        if (temp < 0) {
            cout << 0 << "\n";
            return 0;
        }
        result = max(result, temp);
    }
    cout << result << "\n";
    return 0;
}