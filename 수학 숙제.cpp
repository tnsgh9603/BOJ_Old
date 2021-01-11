#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector <string> vec;
bool compare(string a, string b) {
    if (a.length() < b.length()) {
        return true;
    }
    else if (a.length() == b.length()) {
        if (a < b) {
            return true;
        }
    }
    return false;
}
int main() {
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            // 숫자의 첫 시작을 찾음
            if (s[i] >= '0' && s[i] <= '9') {
                int start = i;
                // 숫자가 끝날때까지 탐색
                while (s[i] >= '0' && s[i] <= '9') {
                    i++;
                }
                int end = i;
                // 숫자열을 s2에 저장
                string s2 = s.substr(start, end - start);
                // 0의 개수를 cnt에 저장
                int cnt = 0;
                // 0의 개수를 셈
                for (int q = 0; q < s2.size(); q++) {
                    if (s2[q] == '0') {
                        cnt++;
                    }
                }
                // 모두 0이면 0을 vec에 저장
                if (cnt == s2.size()) {
                    vec.push_back("0");
                }
                // 앞에 있는 0들을 제거
                // ex) 0002 -> 2
                for (int j = 0; j < s2.size(); j++) {
                    if (s2[j] != '0') {
                        s2 = s2.substr(j);
                        vec.push_back(s2);
                        break;
                    }
                }
            }
        }
    }
    // 길이 순으로 오름차순, 길이가 같다면 비교하여 오름차순으로 정렬
    sort(vec.begin(), vec.end(), compare);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
    }
    return 0;
}