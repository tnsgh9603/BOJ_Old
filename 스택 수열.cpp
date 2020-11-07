#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
	stack <int> st;
	vector <int> arr;
	vector <string> vec;
	int n, input, j = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		arr.push_back(input);
	}
	for (int i = 1; i <= n; i++) {
		st.push(i);
		vec.push_back("+");
		while (!st.empty() && arr[j] == st.top()) {
			st.pop();
			vec.push_back("-");
			j++;
		}
	}
	if (!st.empty()) {
		cout << "NO";
	}
	else {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << "\n";
		}
	}
	return 0;
}