#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> addition, subtraction;
int main() {
    int N, k, zero = 0, one = 0, ans = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> k;
        if (k == 1) {
            one++;
        }
        else if (k > 0) {
            addition.push_back(k);
        }
        else if (k < 0) {
            subtraction.push_back(k);
        }
        else {
            zero++;
        }
    }

    // �������� ����
    sort(addition.begin(), addition.end(), greater<int>());
    // �������� ����
    sort(subtraction.begin(), subtraction.end());

    // ������ �����ֱ� ���� 1�� �־���
    if (addition.size() % 2 == 1) {
        addition.push_back(1);
    }
    // �굵 ���������� ������ �����ֱ� ���� 
    // minus������ zero�� ������ 0�� �־��ְ� ������ 1�� �־��ش�.
    if (subtraction.size() % 2 == 1) {
        subtraction.push_back(zero > 0 ? 0 : 1);
    }
    for (int i = 0; i < addition.size(); i += 2) {
        ans += addition[i] * addition[i + 1];
    }
    for (int i = 0; i < subtraction.size(); i += 2) {
        ans += subtraction[i] * subtraction[i + 1];
    }
    ans = ans + one;
    cout << ans;
    return 0;
}
