#include <iostream>
using namespace std;
int item[101][2] = { 0, }, dp[101][100001] = { 0, }; // dp[a][b] -> ���濡 ���� b���� �� �� �ְ�, �� ���濡 a���� ������ ���� ���� ���ǵ��� ��ġ�� �ִ����� ������ �迭
int main(){
    int N, K;
    cin >> N >> K; // ��ǰ�� �� : N, ��ƿ �� �ִ� ���� : K
    for (int i = 1; i <= N; i++){
        cin >> item[i][0] >> item[i][1]; // [0]�� ����, [1]�� ��ġ�� ����
    }
    for (int i = 1; i <= N; i++){
        int weight = item[i][0], value = item[i][1];
        for (int j = 0; j <= K; j++){
            if (j < item[i][0]) { // ���� �賶 ���԰� �ش� ������ ������ ���� ���ϴ� �����̸�
                dp[i][j] = dp[i - 1][j]; // ���� ������ �����϶��� ��ġ�� �־��ش�.
            }
            else { // ���� �� �ִٸ�
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value); // ����� ���� �� ��������� ��ġ�� ���Ѵ�.
            }
        }
    }
    cout << dp[N][K];
}