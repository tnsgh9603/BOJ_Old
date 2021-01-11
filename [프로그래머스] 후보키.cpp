#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
// �ּҼ� �˻�
bool check(int bit) {
    for (int i = 0; i < vec.size(); i++) {
        // �ּҼ��� �������� ���ϴ� ���
        if ((vec[i] & bit) == vec[i]) {
            return false;
        }
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int row = relation.size(), col = relation[0].size();
    // �� ����� ���� 2^(col) - 1 ���̴�.
    for (int i = 1; i < (1 << col); i++) {
        map<string, int> mp;
        for (int j = 0; j < row; j++) {
            string now;
            // ��� ������ ���� üũ�غ�
            for (int k = 0; k < col; k++) {
                if (i & (1 << k)) {
                    now += relation[j][k];
                }
            }
            mp[now] = 1;
        }
        // ���ϼ��� �ּҼ� �� �� �����Ѵٸ� vec�� push
        if (mp.size() == row && check(i)) {
            vec.push_back(i);
        }
    }
    return vec.size();
}
int main() {
    vector<vector<string>> relation;
    vector<string> s1;
    vector<string> s2;
    vector<string> s3;
    vector<string> s4;
    vector<string> s5;
    vector<string> s6;
    s1.push_back("100");
    s1.push_back("ryan");
    s1.push_back("music");
    s1.push_back("2");
    s2.push_back("200");
    s2.push_back("apeach");
    s2.push_back("math");
    s2.push_back("2");
    s3.push_back("300");
    s3.push_back("tube");
    s3.push_back("computer");
    s3.push_back("3");
    s4.push_back("400");
    s4.push_back("con");
    s4.push_back("computer");
    s4.push_back("4");
    s5.push_back("500");
    s5.push_back("muzi");
    s5.push_back("music");
    s5.push_back("3");
    s6.push_back("600");
    s6.push_back("apeach");
    s6.push_back("music");
    s6.push_back("2");
    relation.push_back(s1);
    relation.push_back(s2);
    relation.push_back(s3);
    relation.push_back(s4);
    relation.push_back(s5);
    relation.push_back(s6);
    cout << solution(relation);
}