#include <iostream>
using namespace std;
int item[101][2] = { 0, }, dp[101][100001] = { 0, }; // dp[a][b] -> 가방에 무게 b까지 들어갈 수 있고, 그 가방에 a개의 물건을 넣을 때의 물건들의 가치의 최대합을 저장한 배열
int main(){
    int N, K;
    cin >> N >> K; // 물품의 수 : N, 버틸 수 있는 무게 : K
    for (int i = 1; i <= N; i++){
        cin >> item[i][0] >> item[i][1]; // [0]에 무게, [1]에 가치를 넣음
    }
    for (int i = 1; i <= N; i++){
        int weight = item[i][0], value = item[i][1];
        for (int j = 0; j <= K; j++){
            if (j < item[i][0]) { // 현재 배낭 무게가 해당 차례의 물건을 담지 못하는 무게이면
                dp[i][j] = dp[i - 1][j]; // 전번 차례의 물건일때의 가치를 넣어준다.
            }
            else { // 담을 수 있다면
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value); // 담았을 때와 안 담았을때의 가치를 비교한다.
            }
        }
    }
    cout << dp[N][K];
}