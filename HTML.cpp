#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s;
    int sum = 0; // ���� �ٿ� ��ĭ�� �Է��ߴ��� �޾��ִ� sum ����
    bool sameline = false; // ���� ���̸� True, �ٸ� ���̸� false ��ȯ
    while (cin >> s){ // ���� ������ ��� s�� �Է�
        if (s == "<br>"){ // "<br>"�� �Է� ���� ��� �� �� ���
            cout << "\n";
            sum = 0; // sum�� 0���� �ʱ�ȭ
        }
        else if (s == "<hr>"){ // <hr>�� �Է¹��� �� �� �� ���� '-' x 80 ���
            if (!sum){ // �� ó���� <"hr">�� �Է� �޾��� ��� �ٷ� '-' x 80
                for (int i = 0; i < 80; i++){
                    cout << "-";
                }
                cout << "\n";
            }
            else{ // �� �߰��� "<hr>"�� �Է� �޾��� ��� �� �� �̸� �����
                sum = 0;
                cout << "\n"; 
                for (int i = 0; i < 80; i++){
                    cout << "-";
                }
                cout << "\n";
            }
        }
        else{ // "<hr>", "<br>"���� �ٸ� ���� �Է¹�����
            int len = s.length();
            if (!sum){
                sum = len;
                cout << s;
                sameline = true;
            }
            else if (sum + len + 1 <= 80){ // �ܾ� �Է��ص� 80ĭ �����϶�
                if (sameline){ // ���� �� ĭ ��ŭ �����
                    cout << " ";
                    sum += 1;
                }
                sum += len; // ���ڿ� ���̸�ŭ sum�� ������
                cout << s;
                if (sum == 80){
                    cout << "\n";
                    sum = 0;
                    sameline = false;
                }
            }
            else{ // �ܾ ������ 80ĭ�� �Ѿ ��� �׳� ���� �ٿ� ����
                cout << "\n";
                sum = len;
                sameline = true;
                cout << s;
            }
        }
    }
    return 0;
}
/*
//sol2) �Ľ� ���� (getline + regex_replace�� �� �ٷ� �� �ٿ��� �ް�, regex iterator�� �̿�)
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    string s, temp;
    while (getline(cin, temp)) {
        if (temp == "") continue;
        if (temp.back() != ' ') temp.push_back(' ');
        s += temp;
    }
    temp.clear();
    regex r(R"(\s?([^\s\t]+)(\s.+)?)");
    regex r2(R"([\s\t]+)");
    s = regex_replace(s, r2, " ");
    vector<string> v;
    while (1) {
        auto it = *sregex_iterator(s.begin(), s.end(), r);
        string arr[3];
        for (int i = 1; i <= 2; i++) arr[i] = it[i];
        v.push_back(arr[1]);
        if (arr[2].empty()) break;
        s = arr[2];
    }
    int length = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "<br>") {
            length = 0;
            cout << '\n';
            continue;
        }
        if (v[i] == "<hr>") {
            if (length != 0) cout << '\n';
            length = 0;
            cout << string(80, '-') << '\n';
            continue;
        }
        if (length + v[i].size() > 80) {
            length = 0;
            cout << '\n';
        }
        cout << v[i] << ' ';
        length += v[i].size() + 1;
    }
}*/