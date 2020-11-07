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
        // '(' 일 경우에는 스택에 넣어준다.
        if (input[i] == '(') {
            s.push(input[i]);
        }
        // ')' 일 경우에는 스택에서 빼준다.
        else {
            s.pop();
            //레이저일 경우
            if (input[i - 1] == '('){
                result += s.size(); //스택의 사이즈만큼 더해준다.
            }
            //막대기의 끝일 경우
            else {
                result++;    //1을 더해준다.
            }
        }
    }
    cout << result << "\n";
    return 0;
}