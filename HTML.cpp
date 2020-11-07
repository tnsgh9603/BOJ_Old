#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s;
    int sum = 0; // 지금 줄에 몇칸을 입력했는지 받아주는 sum 변수
    bool sameline = false; // 같은 줄이면 True, 다른 줄이면 false 반환
    while (cin >> s){ // 공백 단위로 끊어서 s에 입력
        if (s == "<br>"){ // "<br>"을 입력 받을 경우 한 줄 띄움
            cout << "\n";
            sum = 0; // sum은 0으로 초기화
        }
        else if (s == "<hr>"){ // <hr>을 입력받을 시 한 줄 띄우고 '-' x 80 출력
            if (!sum){ // 줄 처음에 <"hr">을 입력 받았을 경우 바로 '-' x 80
                for (int i = 0; i < 80; i++){
                    cout << "-";
                }
                cout << "\n";
            }
            else{ // 줄 중간에 "<hr>"을 입력 받았을 경우 한 줄 미리 띄워줌
                sum = 0;
                cout << "\n"; 
                for (int i = 0; i < 80; i++){
                    cout << "-";
                }
                cout << "\n";
            }
        }
        else{ // "<hr>", "<br>"말고 다른 것을 입력받을때
            int len = s.length();
            if (!sum){
                sum = len;
                cout << s;
                sameline = true;
            }
            else if (sum + len + 1 <= 80){ // 단어 입력해도 80칸 이하일때
                if (sameline){ // 공백 한 칸 만큼 띄워줌
                    cout << " ";
                    sum += 1;
                }
                sum += len; // 문자열 길이만큼 sum에 더해줌
                cout << s;
                if (sum == 80){
                    cout << "\n";
                    sum = 0;
                    sameline = false;
                }
            }
            else{ // 단어를 적으면 80칸이 넘어갈 경우 그냥 다음 줄에 적음
                cout << "\n";
                sum = len;
                sameline = true;
                cout << s;
            }
        }
    }
    return 0;
}
/*
//sol2) 파싱 구현 (getline + regex_replace로 한 줄로 다 붙여서 받고, regex iterator를 이용)
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    string s, temp;
    while (getline(cin, temp)) {
        if (temp == "") continue;
        if (temp.back() != ' ') temp.push_back(' ');
        s += temp;
    }
    temp.clear();
    regex r(R"(\s?([^\s\t]+)(\s.+)?)");
    regex r2(R"([\s\t]+)");
    s = regex_replace(s, r2, " ");
    vector<string> v;
    while (1) {
        auto it = *sregex_iterator(s.begin(), s.end(), r);
        string arr[3];
        for (int i = 1; i <= 2; i++) arr[i] = it[i];
        v.push_back(arr[1]);
        if (arr[2].empty()) break;
        s = arr[2];
    }
    int length = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "<br>") {
            length = 0;
            cout << '\n';
            continue;
        }
        if (v[i] == "<hr>") {
            if (length != 0) cout << '\n';
            length = 0;
            cout << string(80, '-') << '\n';
            continue;
        }
        if (length + v[i].size() > 80) {
            length = 0;
            cout << '\n';
        }
        cout << v[i] << ' ';
        length += v[i].size() + 1;
    }
}*/