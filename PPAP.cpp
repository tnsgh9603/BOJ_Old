#include <iostream>
#include <string>
using namespace std;
int main() {
	int cnt = 0;
	string sentence;
	cin >> sentence;
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence[i] == 'P') {
			cnt++; 
			continue;
		}
		// �տ� p�� 2���̻� ���Ӱ� ���� ���� P�϶�
		// ���� p���� ����������Ƿ� i++
		// ppap�� p�� ��������Ƿ�  cnt--
		if (cnt >= 2 && sentence[i] == 'A' && sentence[i + 1] == 'P') {
			cnt--;
			i++;
		}
		else {
			cout << "NP";
			return 0;
		}
	}
	// �������� p�� �����°�?
	if (cnt == 1) {
		cout << "PPAP\n";
	}
	else {
		cout << "NP\n";
	}
	return 0;
}