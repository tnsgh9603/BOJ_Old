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
		// ������ ��� ������ ���� ����, ��������� ������ ���� ���ڰ� �ƴϴ�. 
		if (s.empty()) {
			result++;
		}
		// ���� �ʱ�ȭ
		while (!s.empty()) {
			s.pop();
		}
	}
	cout << result;
	return 0;
}