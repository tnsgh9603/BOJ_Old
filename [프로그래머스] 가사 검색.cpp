#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//길이로 먼저 정렬하고 길이가 같다면 사전순으로 정렬
bool compare(string a, string b) {
    if (a.length() < b.length()) {
        return true;
    }
    else if (a.length() == b.length()) {
        if (a < b) {
            return true;
        }
    }
    return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    //rwords 벡터에 단어를 뒤집어서 저장
    vector<string> rwords = words;
    int size = rwords.size();
    for (int i = 0; i < size; i++) {
        reverse(rwords[i].begin(), rwords[i].end());
    }

    //compare 기준 정렬
    sort(words.begin(), words.end(), compare);
    sort(rwords.begin(), rwords.end(), compare);

    int len, lo, hi, idx;
    for (string query : queries) {
        len = query.length();

        if (query[0] == '?') {
            //?가 접두사에 있는 경우
            reverse(query.begin(), query.end()); //키워드도 뒤집어준다.
            idx = query.find_first_of('?');

            for (int i = idx; i < len; i++) {
                query[i] = 'a';
            }
            lo = lower_bound(rwords.begin(), rwords.end(), query, compare) - rwords.begin();

            for (int i = idx; i < len; i++) {
                query[i] = 'z';
            }
            hi = upper_bound(rwords.begin(), rwords.end(), query, compare) - rwords.begin();
        }
        else {
            //?가 접미사에 있는 경우
            idx = query.find_first_of('?');

            for (int i = idx; i < len; i++) query[i] = 'a';
            lo = lower_bound(words.begin(), words.end(), query, compare) - words.begin();

            for (int i = idx; i < len; i++) query[i] = 'z';
            hi = upper_bound(words.begin(), words.end(), query, compare) - words.begin();
        }
        answer.push_back(hi - lo);
    }
    return answer;
}
