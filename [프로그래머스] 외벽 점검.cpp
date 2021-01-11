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

        // ���� 1 : ���� ����ŭ�� �ݺ��ϱ� ���� ����
        // ���� 2 : ������ �����Ǿ� �ִ� �ּ� �ο����� �� ���ٸ� �� �����ʹ� �ǹ̾��� Ž���� �ǹǷ�
        // ���� 3 : �ܺ��� ��� �����Ͽ�����(flag == true)
        for (int j = 0; (j < vec.size()) && (j + 1 < answer) && (!flag); j++) {
            int end = weak[weak_index] + dist[vec[j]];
            while (end >= weak[weak_index]) {
                weak_index++;
                if (weak_index == weak.size()) {
                    // vec�� ����Ǿ� �ִ� '0��° ���'�� �̾Ҵٰ� �ϴ���, ������ ���� �ο��� 0���� �ƴ� 1���̱� ������, ��� �ο����� j + 1�� ��
                    cnt = j + 1;
                    flag = true;
                    answer = min(answer, cnt);
                    break;
                }
            }
        }
        // ���� ���� ���������� �ٲپ� ����
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
        // �湮�Ѱ�� ����
        if (visited[i] == true) {
            continue;
        }
        // �湮 üũ
        visited[i] = true;
        vec.push_back(i);
        dfs(cnt + 1, weak, dist, n);
        vec.pop_back();
        visited[i] = false;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    // �������� ����
    sort(dist.begin(), dist.end(), less<int>());
    vector<int> temp = weak;
    // ���� ���� ������ �� �ִ� ģ���� ȥ�ڼ� ����������� �̵��� ��� �������� ���� üũ
    for (int i = 0; i < temp.size(); i++) {
        int start = temp[0];
        int end = temp[temp.size() - 1];
        // ���� ���� ������ �� �ִ� ģ���� ȥ�ڼ� ����������� �̵��� ��� ������ ���
        if (end - start <= dist[0]) {
            return 1;
        }
        // ���� ���� ���������� �ٲپ� ����
        int start_value = temp[0];
        for (int j = 1; j < temp.size(); j++) {
            temp[j - 1] = temp[j];
        }
        temp[temp.size() - 1] = start_value + n;
    }
    dfs(0, weak, dist, n);
    // ��� �����ص� �� �Ǵ� ���
    if (answer == INT_MAX) {
        return -1;
    }
    return answer;
}