#include <iostream>
#include <string>
using namespace std;
int main() {
	bool flag1 = true;
	string input, reverse_input, ans, ans2;
	int cnt = 0;
	cin >> input;
	
	// 회문을 찾을 때까지 반복
	while(flag1){
		//한번 이상 돌았을 때의 변수 초기화
		if (cnt >= 1) {
			input = ans2;
			ans = "";
			ans2 = "";
			reverse_input = "";
		}
		// 마지막 자리수 계산에 올림수가 있는지 체크하기 위한 flag2
		bool flag2 = true;
		// next는 더할때 올림수의 역할
		int next = 0;

		// 입력한 문장을 뒤집은 reverse_input을 만듬
		for (int i = input.length() - 1; i >= 0; i--) {
			reverse_input = reverse_input + input[i];
		}
		// 첫 문장과 뒤집은 문장을 더하는 과정
		for (int i = 0; i < input.length(); i++) {
			// 각각의 자리수를 더함
			int sum = reverse_input[i] + input[i] - 'a' - 'a' + next;
			// 올림수가 필요없으면
			if (sum <= 25) {
				ans += char(sum + 97);
				next = 0;
			}
			// 올림수가 필요하면
			if (sum > 25) {
				ans += char(sum + 71);
				next = 1;
				// 마지막 자리수 계산에 올림수가 있을경우
				if (i == input.length() - 1) {
					flag2 = false;
				}
			}
		}
		// 문자열을 뒤집어서 최종 문자열을 완성해줌
		for (int i = ans.length() - 1; i >= 0; i--) {
			ans2 = ans2 + ans[i];
		}
		// 마지막 자리수 계산에 올림수가 있으면 문자열 앞에 b를 더해줌
		if (!flag2) {
			ans2 = "b" + ans2;
		}
		// 입력한 문장과 뒤집은 문장이 회문이면 탈출
		for (int i = 0; i < ans2.length() / 2; i++) {
			if (ans2[i] != ans2[ans2.length() - i - 1]) {
				break;
			}
			if (i == ans2.length() / 2 - 1) {
				flag1 = false;
			}
		}
		// 회문을 못 찾았으면 cnt++후 다시 while문 진행
		cnt++;
	}
	cout << ans2;
}