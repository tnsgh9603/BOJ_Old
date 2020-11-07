#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, M, K;
int ans = 1;
bool flag;

queue <pair<pair<int, int>,int>> q;
int map[1001][1001];
bool visited[1001][1001][11]; // 방문했다는것을 표시

int main(){
    string str;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++){
        cin >> str;
        for (int j = 1; j <= M; j++){
            map[i][j] = str[j - 1] - '0'; // string으로 받아줬으니 - '0' 빼줌
        }
    }

    q.push(make_pair(make_pair(1, 1), 0));
    visited[1][1][0] = true;

    while (!q.empty()){ // q가 빌 때까지
        int qsize = q.size();
        while (qsize--){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int gowall = q.front().second;
            q.pop();

            if (x == N && y == M){ // 도착했으면 break;
                flag = true;
                break;
            }

            for (int i = 0; i < 4; i++){
                int mx = x + "1102"[i] - '1';
                int my = y + "2011"[i] - '1';
                int ngowall = map[mx][my]; // 1이면 벽을 부숴야 갈 수 있다.

                if (mx >= 1 && mx <= N && my >= 1 && my <= M){ // 배열 범위를 초과 안했을때만 고려
                    if ((gowall + ngowall) > K) { // 벽을 k번까지 부술 수 있다. k번이 넘어가면 continue
                        continue;
                    }
                    ngowall += gowall; // 벽 부순 회수 추가
                    if (visited[mx][my][ngowall]) { // 방문 했었다면 제외
                        continue;
                    }
                    // 방문 안했으면 방문 표시 후 푸쉬푸쉬
                    q.push(make_pair(make_pair(mx, my), ngowall)); 
                    visited[mx][my][ngowall] = true;
                }
            }
        }
        if (flag) {
            break;
        }
        else {
            ans++;
        }
    }

    if (flag) {
        cout << ans;
    }
    else {
        cout << -1;
    }
    return 0;
}