#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int number;
int main() {
	fastio;
	string answer, hour[13] = { "","one","two","three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve" },minute[31] = { "","one minute","two minutes","three minutes", "four minutes",
		"five minutes", "six minutes", "seven minutes", "eight minutes", "nine minutes",
		"ten minutes", "eleven minutes", "twelve minutes","thirteen minutes","fourteen minutes",
	"quarter","sixteen minutes" ,"seventeen minutes","eighteen minutes" ,"nineteen minutes",
	"twenty minutes","twenty one minutes", "twenty two minutes", "twenty three minutes", "twenty four minutes",
	"twenty five minutes", "twenty six minutes", "twenty seven minutes", "twenty eight minutes","twenty nine minutes"
	,"half" };
	int h, m;
	cin >> h >> m;
	if (!m) {
		answer = hour[h] + " o' clock";
	}
	else if (m >= 1 && m <= 30) {
		answer = minute[m] + " past " + hour[h];
	}
	else if (m > 30) {
		if (h == 12) {
			h = 0;
		}
		number = 60 - m;
		answer = minute[number] + " to " + hour[h + 1];
	}
	cout << answer;
	return 0;
}