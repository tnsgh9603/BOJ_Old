#include <iostream>
#include <stack>
using namespace std;
stack <int> st;
int main() {
	int K, input, sum = 0;
	cin >> K;
	for (int i = 1; i <= K; i++) {
		cin >> input;
		if (input == 0) {
			st.pop();
		}
		else {
			st.push(input);
		}
	}
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum;
	return 0;
}