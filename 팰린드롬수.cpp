#include <iostream>
using namespace std;
int main() {
	string input;
	while (1) {
		int t = 0;
		cin >> input;
		if (input == "0") {
			break;
		}
		for (int i = 0; i < input.size() / 2; i++) {
			if (input[i] != input[input.size() - i - 1]) {
				t = 1;
			}
		}
		printf("%s\n", t ? "no" : "yes");
	}
}