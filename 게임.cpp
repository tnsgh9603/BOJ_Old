#include <iostream>
using namespace std;
int main() {
    long long x, y, z, original_probability, start = 1, end = 1000000000, ans = -1;
    cin >> x >> y;
    original_probability = (y * 100 / x);
    // Ȯ���� 99�ΰų� 100�� ��쿡�� �ٲ� �� ����.
    if (original_probability == 99 || original_probability == 100) {
        cout << "-1";
        return 0;
    }
    while (start <= end) {
        long long mid = (start + end) / 2, new_probablity = (y + mid) * 100 / (x + mid);
        if (new_probablity > original_probability) {
            end = mid - 1, ans = mid;
        }
        else {
            start = mid + 1;
        }
    }
    cout << ans;
    return 0;
}