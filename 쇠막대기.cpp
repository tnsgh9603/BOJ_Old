#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    string input;
    stack <char> s;
    int result = 0;
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        // '(' �� ��쿡�� ���ÿ� �־��ش�.
        if (input[i] == '(') {
            s.push(input[i]);
        }
        // ')' �� ��쿡�� ���ÿ��� ���ش�.
        else {
            s.pop();
            //�������� ���
            if (input[i - 1] == '('){
                result += s.size(); //������ �����ŭ �����ش�.
            }
            //������� ���� ���
            else {
                result++;    //1�� �����ش�.
            }
        }
    }
    cout << result << "\n";
    return 0;
}