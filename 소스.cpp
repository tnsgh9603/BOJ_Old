#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<string> sol_jinhan(vector<string>& input) {
    vector<string> ret;
    for (auto s : input) {
        for (auto& i : s) if (i & (1 << 6)) i = ' ';
        stringstream in(s);
        while (in >> s) {
            int i;
            for (i = 0; i < s.size(); i++) if (s[i] != '0') break;
            if (i == s.size()) ret.push_back(string("0"));
            else ret.push_back(s.substr(i, s.size()));
        }
    }
    sort(ret.begin(), ret.end(), [&](string a, string b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
        });
    return ret;
}

vector<string> sol_sunho(vector<string>& input) {
    vector<string> ret;
    for (auto s : input) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int start = i;
                while (s[i] >= '0' && s[i] <= '9') i++;
                int end = i;
                string s2 = s.substr(start, end - start);
                bool flag = false;
                for (int j = 0; j < s2.size() - 1; j++) {
                    if (s2[j] == '0' && (s2[j + 1] > '0' && s2[j + 1] <= '9')) {
                        s2 = s2.substr(j + 1);
                        flag = true;
                        ret.push_back(s2);
                        break;
                    }
                }
                if (s2[0] != '0' && !flag) {
                    flag = true;
                    ret.push_back(s2);
                }
                if (!flag) ret.push_back("0");
            }
        }
    }
    sort(ret.begin(), ret.end(), [&](string a, string b) {
        if (a.length() < b.length()) return true;
        else if (a.length() == b.length()) if (a < b) return true;
        return false;
        });
    return ret;
}

int main() {
    fastio;
    int cnt = 0;
    while (1) {
        int n = rand() % 10 + 1;
        vector<string> input;
        for (int j = 0; j < n; j++) {
            string s;
            int m = rand() % 10 + 1;
            for (int i = 0; i < m; i++) {
                int t = rand() % (26 + 10);
                if (t < 26) s.push_back('a' + t);
                else s.push_back('0' + t - 26);
            }
            input.push_back(s);
        }
        if (sol_jinhan(input) != sol_sunho(input)) {
            cout << string(30, '=') << '\n';
            cout << n << '\n';
            for (auto i : input) cout << i << '\n';
            if (++cnt == 10) break;
        }
    }
    cout << string(30, '=') << '\n';
}