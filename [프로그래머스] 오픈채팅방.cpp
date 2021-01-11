#include <bits/stdc++.h>
using namespace std;
map <string, string> mp;
vector <pair<string, string>> vec;
vector<string> ans;
vector<string> solution(vector<string> record) {
	for (auto s : record) {
		string s1, s2, s3;
		stringstream ss(s);
		ss >> s1 >> s2 >> s3;
		if (s1 == "Enter") {
			vec.push_back({ "님이 들어왔습니다.",s2 });
			mp[s2] = s3;
		}
		else if (s1 == "Leave") {
			vec.push_back({ "님이 나갔습니다.",s2 });
		}
		else{
			mp[s2] = s3;
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		ans.push_back(mp[vec[i].second] + vec[i].first);
	}
	return ans;
}