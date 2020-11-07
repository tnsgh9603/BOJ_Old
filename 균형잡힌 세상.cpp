#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<int> st;
int main() {
    string S;
    while (1) {
        getline(cin, S);
        if (S[0] == '.') { // ������ �Է� ������ �Է� ���ڿ� �������� .�� ������ ���̹Ƿ� S.length() == 1�� �ʿ� ����.
            break;
        }
        //������ �ʱ�ȭ�Ѵ�.
        while (!st.empty()) {
            st.pop();
        }
        //S�� ��ȸ�ϸ鼭 ���๮��('[(')�� ������ ���ÿ� �־��ְ�, �ݴ� �κп��� ¦�� �´��� Ȯ���Ѵ�.
        //¦�� ���� �ʴ´ٸ�, break;
        bool flag = true;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                st.push(1);
            }
            else if (S[i] == '[') {
                st.push(2);
            }
            else if (S[i] == ')') {
                if (!st.empty() && st.top() == 1) {
                    st.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
            else if (S[i] == ']') {
                if (!st.empty() && st.top() == 2) {
                    st.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag && st.empty()) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
    return 0;
}
