#include <iostream>
#include <string>
using namespace std;
int main() {
	bool flag1 = true;
	string input, reverse_input, ans, ans2;
	int cnt = 0;
	cin >> input;
	
	// ȸ���� ã�� ������ �ݺ�
	while(flag1){
		//�ѹ� �̻� ������ ���� ���� �ʱ�ȭ
		if (cnt >= 1) {
			input = ans2;
			ans = "";
			ans2 = "";
			reverse_input = "";
		}
		// ������ �ڸ��� ��꿡 �ø����� �ִ��� üũ�ϱ� ���� flag2
		bool flag2 = true;
		// next�� ���Ҷ� �ø����� ����
		int next = 0;

		// �Է��� ������ ������ reverse_input�� ����
		for (int i = input.length() - 1; i >= 0; i--) {
			reverse_input = reverse_input + input[i];
		}
		// ù ����� ������ ������ ���ϴ� ����
		for (int i = 0; i < input.length(); i++) {
			// ������ �ڸ����� ����
			int sum = reverse_input[i] + input[i] - 'a' - 'a' + next;
			// �ø����� �ʿ������
			if (sum <= 25) {
				ans += char(sum + 97);
				next = 0;
			}
			// �ø����� �ʿ��ϸ�
			if (sum > 25) {
				ans += char(sum + 71);
				next = 1;
				// ������ �ڸ��� ��꿡 �ø����� �������
				if (i == input.length() - 1) {
					flag2 = false;
				}
			}
		}
		// ���ڿ��� ����� ���� ���ڿ��� �ϼ�����
		for (int i = ans.length() - 1; i >= 0; i--) {
			ans2 = ans2 + ans[i];
		}
		// ������ �ڸ��� ��꿡 �ø����� ������ ���ڿ� �տ� b�� ������
		if (!flag2) {
			ans2 = "b" + ans2;
		}
		// �Է��� ����� ������ ������ ȸ���̸� Ż��
		for (int i = 0; i < ans2.length() / 2; i++) {
			if (ans2[i] != ans2[ans2.length() - i - 1]) {
				break;
			}
			if (i == ans2.length() / 2 - 1) {
				flag1 = false;
			}
		}
		// ȸ���� �� ã������ cnt++�� �ٽ� while�� ����
		cnt++;
	}
	cout << ans2;
}