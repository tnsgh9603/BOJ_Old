#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector <string> genres;
vector <int> plays;
vector<int> answer;
vector<pair <string, int>> vec;
vector<pair <int, string>> temp;
vector<pair <int, int>> max_value;

int main() {
    int song_number, play_number;
    string genre;
    cin >> song_number;

    for (int i = 1; i <= song_number; i++) {
        cin >> genre;
        cin >> play_number;
        genres.push_back(genre);
        plays.push_back(play_number);
    }

    for (int i = 0; i < genres.size(); i++) {
        vec.push_back(make_pair(genres[i], plays[i]));
    }

    for (int i = 0; i < genres.size(); i++) {
        temp.push_back(make_pair(plays[i], genres[i]));
        for (int j = i + 1; j < genres.size(); j++) {
            // 장르가 같으면 재생 횟수를 더해주고 그 배열을 지운다.
            if (genres[i] == genres[j]) {
                temp[i].first += plays[j];
                genres.erase(genres.begin() + j);
                plays.erase(plays.begin() + j);
                j--;
            }
        }
    }
    // 재생횟수 기준 내림차순 정렬
    // temp의 첫번째 요소는 재생횟수, 두 번째 요소는 장르
    sort(temp.begin(), temp.end(), greater<pair<int, string>>());

    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            // 장르가 같으면 min_value에 재생횟수와 고유 인덱스 값을 넣어준다.
            if (temp[i].second == vec[j].first) {
                max_value.push_back(make_pair(vec[j].second, j));
            }
        }
        sort(max_value.begin(), max_value.end(), greater<pair<int, int>>());
        // 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록한다.
        if (max_value.size() >= 2) {
            if (max_value[0].first == max_value[1].first) {
                answer.push_back(max_value[1].second);
                answer.push_back(max_value[0].second);
            }
            else {
                answer.push_back(max_value[0].second);
                answer.push_back(max_value[1].second);
            }
        }
        else {
            answer.push_back(max_value[0].second);
        }
        // max_value 벡터의 size를 0으로 만들어 줌
        max_value.clear();
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
}