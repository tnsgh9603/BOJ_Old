#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//���̷� ���� �����ϰ� ���̰� ���ٸ� ���������� ����
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

    //rwords ���Ϳ� �ܾ ����� ����
    vector<string> rwords = words;
    int size = rwords.size();
    for (int i = 0; i < size; i++) {
        reverse(rwords[i].begin(), rwords[i].end());
    }

    //compare ���� ����
    sort(words.begin(), words.end(), compare);
    sort(rwords.begin(), rwords.end(), compare);

    int len, lo, hi, idx;
    for (string query : queries) {
        len = query.length();

        if (query[0] == '?') {
            //?�� ���λ翡 �ִ� ���
            reverse(query.begin(), query.end()); //Ű���嵵 �������ش�.
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
            //?�� ���̻翡 �ִ� ���
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
