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
            // �帣�� ������ ��� Ƚ���� �����ְ� �� �迭�� �����.
            if (genres[i] == genres[j]) {
                temp[i].first += plays[j];
                genres.erase(genres.begin() + j);
                plays.erase(plays.begin() + j);
                j--;
            }
        }
    }
    // ���Ƚ�� ���� �������� ����
    // temp�� ù��° ��Ҵ� ���Ƚ��, �� ��° ��Ҵ� �帣
    sort(temp.begin(), temp.end(), greater<pair<int, string>>());

    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            // �帣�� ������ min_value�� ���Ƚ���� ���� �ε��� ���� �־��ش�.
            if (temp[i].second == vec[j].first) {
                max_value.push_back(make_pair(vec[j].second, j));
            }
        }
        sort(max_value.begin(), max_value.end(), greater<pair<int, int>>());
        // �帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����Ѵ�.
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
        // max_value ������ size�� 0���� ����� ��
        max_value.clear();
    }
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
}