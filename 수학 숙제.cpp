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
            // ������ ù ������ ã��
            if (s[i] >= '0' && s[i] <= '9') {
                int start = i;
                // ���ڰ� ���������� Ž��
                while (s[i] >= '0' && s[i] <= '9') {
                    i++;
                }
                int end = i;
                // ���ڿ��� s2�� ����
                string s2 = s.substr(start, end - start);
                // 0�� ������ cnt�� ����
                int cnt = 0;
                // 0�� ������ ��
                for (int q = 0; q < s2.size(); q++) {
                    if (s2[q] == '0') {
                        cnt++;
                    }
                }
                // ��� 0�̸� 0�� vec�� ����
                if (cnt == s2.size()) {
                    vec.push_back("0");
                }
                // �տ� �ִ� 0���� ����
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
    // ���� ������ ��������, ���̰� ���ٸ� ���Ͽ� ������������ ����
    sort(vec.begin(), vec.end(), compare);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
    }
    return 0;
}