#include <iostream>
using namespace std;
int main() {
	int a, b;
	while (1) {
		cin >> a;
		cin >> b;
		if (cin.eof() == true) {
			// cin���� �Է¹��� ���� ������
			// cin.eof()�� true�� ��ȯ�Ѵ�. �翬�� �׷��� ������ false ��ȯ
			break;
		}
		cout << a + b << endl;
	}
	return 0;
}