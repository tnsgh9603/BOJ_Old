#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack <char> s;
int main() {
	int num = 1;
	string sentence;
	while (1) {
		int answer = 0, cnt = 0;
		cin >> sentence;
		if (sentence[0] == '-') {
			break;
		}
		for (int i = 0; i < sentence.size(); i++) {
			if (s.empty()){
				if (sentence[i] == '}') {
					s.push('{');
					cnt++;
					answer++;
				}
				else {
					s.push('{');
					cnt++;
				}
			}
			else {
				if (sentence[i] == '}' && s.top()=='{') {
					s.pop();
					cnt--;
				}
				else {
					s.push('{');
					cnt++;
				}
			}
		}
		answer += cnt / 2;
		cout << num << ". " << answer << "\n";
		

		//스택 초기화
		while (!s.empty()) {
			s.pop();
		}
		num++;
	}
	return 0;
}