#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int alphabet[26];
vector<int> vec;
int main() {
    int N, ans = 0, cnt = 9;
    cin >> N;

    string sentence;
    for (int i = 0; i < N; i++) {
        cin >> sentence;
        for (int j = 0; j < sentence.length(); j++) {
            // ���� AAA�� �Է����� ���´ٸ� AAA = 111 * A �̹Ƿ� alpahbet[0] = 111�� �ȴ�.
            alphabet[sentence[j] - 'A'] += (int)pow(10, sentence.length() - j - 1);
        }
    }

    for (int i = 0; i < 26; i++) {
        // �����ϴ� ���ĺ��� �־���
        if (alphabet[i]) {
            vec.push_back(alphabet[i]);
        }
    }

    // �������� ����
    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0; i < vec.size(); i++) {
        ans += vec[i] * (cnt--);
    }
    cout << ans;
    return 0;
}