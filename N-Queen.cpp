#include <iostream>
using namespace std;
bool arr[14][14] = { 0, };
int ans = 0;
bool isvalid(int i, int cnt, int input) {
    int x, y;
    for (x = 0; x < cnt; x++) {
        if (arr[i][x]) {
            return false;
        }
    }
    for (x = cnt - 1, y = i - 1; x>=0 && y >= 0; x-- && y--) {
        if (arr[y][x]) {
            return false;
        }
    }
    for (x = cnt - 1, y = i + 1; x>=0 && y < input; x--&& y++) {
        if (arr[y][x]) {
            return false;
        }
    }
    return true;
}
void dfs(int cnt, int input) {
    int i;
    if (cnt == input) {
        ans++;
        return;
    }
    for (i = 0; i < input; i++) {
        if (!arr[i][cnt] && isvalid(i, cnt, input)) {
            arr[i][cnt] = true;
            dfs(cnt + 1, input);
            arr[i][cnt] = false;
        }
    }
}
int main() {
    int input;
    cin >> input;
    dfs(0, input);
    cout << ans;
    return 0;
}