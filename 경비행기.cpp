#include <iostream>
#include <memory.h>
using namespace std;
int arr[1001][2], n, k, fuel;
bool visited[1001];
int distance(int a, int b, int c, int d) {
    return ((a - c) * (a - c) + (b - d) * (b - d));
}
bool dfs(int i, int cnt) {
    if (!cnt) {
        return false;
    }
    visited[i] = true;
    for (int j = 1; j <= n; j++) {
        // 이미 방문했을 경우에는 false, 다음 목적지까지 현재 연료량으로 갈 수 없으면 false
        if ((!visited[j] && distance(arr[i][0], arr[i][1], arr[j][0], arr[j][1]) <= fuel) && (distance(arr[j][0], arr[j][1], 10000, 10000) <= fuel || dfs(j, cnt - 1))) {
            return true;
        }
    }
    return false;
}

int main() {
    // n : 비행장 수 , k : 중간에 내려서 급유를 받는 최대 횟수 
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        // 비행장(급유지)의 x,y 좌표
        cin >> arr[i][0] >> arr[i][1];
    }
    // high는 10000 x 루트2 (대각선)의 근사값인 15000으로 설정
    int low = 1, high = 15000, mid;
    while (low <= high) {
        memset(visited, 0, sizeof(visited));
        mid = (low + high) / 2;
        // a^2 + b^2 = c^2 해줬으므로, 원래 fuel = mid * 10인데 제곱해줌
        fuel = mid * mid * 100;
        if (dfs(0, k)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << low;
}