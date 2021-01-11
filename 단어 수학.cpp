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
            // 만약 AAA가 입력으로 들어온다면 AAA = 111 * A 이므로 alpahbet[0] = 111가 된다.
            alphabet[sentence[j] - 'A'] += (int)pow(10, sentence.length() - j - 1);
        }
    }

    for (int i = 0; i < 26; i++) {
        // 존재하는 알파벳만 넣어줌
        if (alphabet[i]) {
            vec.push_back(alphabet[i]);
        }
    }

    // 내림차순 정렬
    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0; i < vec.size(); i++) {
        ans += vec[i] * (cnt--);
    }
    cout << ans;
    return 0;
}