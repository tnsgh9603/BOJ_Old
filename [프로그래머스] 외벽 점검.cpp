#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
int answer = INT_MAX;
bool visited[8];
vector<int> vec;

void check(vector<int> weak, vector<int> dist, int n) {
    for (int i = 0; i < weak.size(); i++) {
        int weak_index = 0;
        int cnt;
        bool flag = false;

        // 조건 1 : 뽑은 수만큼만 반복하기 위한 조건
        // 조건 2 : 기존에 설정되어 있는 최소 인원보다 더 많다면 그 때부터는 의미없는 탐색이 되므로
        // 조건 3 : 외벽을 모두 점검하였으면(flag == true)
        for (int j = 0; (j < vec.size()) && (j + 1 < answer) && (!flag); j++) {
            int end = weak[weak_index] + dist[vec[j]];
            while (end >= weak[weak_index]) {
                weak_index++;
                if (weak_index == weak.size()) {
                    // vec에 저장되어 있는 '0번째 사람'을 뽑았다고 하더라도, 실제로 뽑은 인원은 0명이 아닌 1명이기 때문에, 사람 인원수는 j + 1이 됨
                    cnt = j + 1;
                    flag = true;
                    answer = min(answer, cnt);
                    break;
                }
            }
        }
        // 다음 점을 시작점으로 바꾸어 설정
        int start_value = weak[0];
        for (int j = 1; j < weak.size(); j++) {
            weak[j - 1] = weak[j];
        }
        weak[weak.size() - 1] = start_value + n;
    }
}

void dfs(int cnt, vector<int> weak, vector<int> dist, int n) {
    if (cnt == dist.size()) {
        check(weak, dist, n);
        return;
    }
    for (int i = 0; i < dist.size(); i++) {
        // 방문한경우 무시
        if (visited[i] == true) {
            continue;
        }
        // 방문 체크
        visited[i] = true;
        vec.push_back(i);
        dfs(cnt + 1, weak, dist, n);
        vec.pop_back();
        visited[i] = false;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    // 내림차순 정렬
    sort(dist.begin(), dist.end(), less<int>());
    vector<int> temp = weak;
    // 가장 많이 움직일 수 있는 친구가 혼자서 취약지점들의 이동이 모두 가능한지 먼저 체크
    for (int i = 0; i < temp.size(); i++) {
        int start = temp[0];
        int end = temp[temp.size() - 1];
        // 가장 많이 움직일 수 있는 친구가 혼자서 취약지점들의 이동이 모두 가능한 경우
        if (end - start <= dist[0]) {
            return 1;
        }
        // 다음 점을 시작점으로 바꾸어 설정
        int start_value = temp[0];
        for (int j = 1; j < temp.size(); j++) {
            temp[j - 1] = temp[j];
        }
        temp[temp.size() - 1] = start_value + n;
    }
    dfs(0, weak, dist, n);
    // 모두 투입해도 안 되는 경우
    if (answer == INT_MAX) {
        return -1;
    }
    return answer;
}