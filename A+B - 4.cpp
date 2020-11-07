#include <iostream>
using namespace std;
int main() {
	int a, b;
	while (1) {
		cin >> a;
		cin >> b;
		if (cin.eof() == true) {
			// cin으로 입력받은 값이 없으면
			// cin.eof()는 true를 반환한다. 당연히 그렇지 않으면 false 반환
			break;
		}
		cout << a + b << endl;
	}
	return 0;
}