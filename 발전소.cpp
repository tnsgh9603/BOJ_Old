#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
#include <memory.h>
using namespace std;
int N, P;
int Answer = INT_MAX;
int arr[16][16], cost[1 << 16];
string sentence;
int count_working_power_station(int bit) {
    int cnt = 0;
    while (bit != 0) {
        cnt += (bit & 1);
        bit = bit >> 1;
    }
    return cnt;
}
int dfs(int current_state) {
    // P���� �����Ұ� �۵��Ǹ� ����
    if (count_working_power_station(current_state) >= P) {
        return 0;
    }
    if (cost[current_state] != -1) {
        return cost[current_state];
    }
    cost[current_state] = INT_MAX;
    for (int i = 0; i < N; i++) {
        // �ش� �����Ұ� ���������� ����
        if ((current_state & (1 << i)) == 0) {
            continue;
        }
        // �ش� �����Ұ� ���� �ְ� ���� �����Ұ� ���� ������
        for (int j = 0; j < N; j++) {
            if ((current_state & (1 << j)) == 0) {
                // ���� �����Ҹ� �Ѱ�
                int next_bit_state = current_state | (1 << j);
                // ��� ���
                cost[current_state] = min(cost[current_state], arr[i][j] + dfs(next_bit_state));
            }
        }
    }
    return cost[current_state];
}
int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> sentence >> P;
    int bit_state = 0;
    // bit_state�� ���� ���� ����
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == 'Y') {
            bit_state = bit_state | (1 << i);
        }
    }
    memset(cost, -1, sizeof(cost));
    int answer = dfs(bit_state) == INT_MAX ? -1 : dfs(bit_state);
    cout << answer;
    return 0;
}