#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack <char> s;
int main() {
	int N, result = 0;
	string sentence;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sentence;
		for (int k = 0; k < sentence.size(); k++) {
			if (sentence[k] == 'A') {
				if (!s.empty() && s.top() == 'A') {
					s.pop();
				}
				else {
					s.push('A');
				}
			}
			else {
				if (!s.empty() && s.top() == 'B') {
					s.pop();
				}
				else {
					s.push('B');
				}
			}
		}
		// 스택이 비어 있으면 좋은 문자, 비어져있지 않으면 좋은 문자가 아니다. 
		if (s.empty()) {
			result++;
		}
		// 스택 초기화
		while (!s.empty()) {
			s.pop();
		}
	}
	cout << result;
	return 0;
}