#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > vec;
int main() {
	int N, start_month, start_day, end_month, end_day, start = 300, end = 301, ans = 0;
	int maxEnd = 0;
	int maxIndex = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start_month >> start_day >> end_month >> end_day;

		if (start_month * 100 + start_day < 301) {
			start_month = 3;
			start_day = 1;
		}

		if (end_month * 100 + end_day > 1130) {
			end_month = 12;
			end_day = 01;
		}

		vec.push_back(make_pair(start_month * 100 + start_day, end_month * 100 + end_day));
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		if (vec[i].first > start && vec[i].first <= end) {
			if (maxEnd < vec[i].second) {
				maxEnd = vec[i].second;
				maxIndex = i;
			}
			if (vec[i].second == 1201) {
				ans++;
				end = maxEnd;
				break;
			}
			continue;
		}
		else {
			if (end >= maxEnd) {
				break;
			}
			ans++;
			start = end;
			end = maxEnd;
			i--;
		}
	}
	if (end == 1201) {
		cout << ans;
	}
	else {
		cout << 0;
	}
	return 0;
}