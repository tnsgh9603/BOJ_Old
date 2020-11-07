#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;
int main(){
    int start = 0;
    for (int i = 1; i <= 3; i++){      // ���� ���� �Է¹ޱ�
        for (int j = 1; j <= 3; j++){
            int temp;
            cin >> temp; // �迭�� ������� �ʰ� ���ڸ� �� �÷��� ǥ��
            if (temp == 0){
                temp = 9; // ��ĭ�� 0���� ó���ϸ� �� �տ� 0�� ��ġ�� ��, ������ �� �����Ƿ� 9�� �ٲ۴�.
            }
            start = start * 10 + temp;    //���� ���ڸ� int�� ���ڷ� ����
        }
    }
    queue <int> q;
    map <int, int> dist;        // �迭 ��� map�� ����Ѵ�.
    dist[start] = 0; // map<key, value> -> ����� ���� listó�� map[key] = value;�� ����� �� �ִ�.
    q.push(start); // ���ڿ� �ֱ�
    while (!q.empty()){
        int now_num = q.front();
        string now = to_string(now_num);        // now_num�� int���̹Ƿ� string������ �ٲ۴�
        q.pop();

        int nn = now.find('9');        // 9�� ��ġ
        int x = nn / 3;                // 9�� ��ġ�� �ప
        int y = nn % 3;                // 9�� ��ġ�� ����

        for (int k = 0; k < 4; k++){    // 4�������� �̵�
        
            int nx = x + "1120"[k] - '1'; // 0 0 1 -1
            int ny = y + "2011"[k] - '1'; // 1 -1 0 0

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3){        // ��踦 �Ѿ�� ��� x
                string next = now;
                swap(next[3 * x + y], next[3 * nx + ny]);        //���ڷ� ������ ���ڿ��� ������ 4���⿡ ��ġ�� ���ڿ� �ٲ۴� (������ �̵��ϴ� �۾��� �����ϴ� �κ�!)
                int num = stoi(next);                        //�ٽ� int������ �ٲ۴�.
                if (dist.count(num) == 0) {                    //dist.count(a)�� a���%$% key���� ���� �� 1�� return �ϰ�, ���� �� 0�� return�Ѵ�.
                                                               //��, ������ �ʾҴ� ����(�湮���� �ʾҴ� ��)�� ī��Ʈ�Ѵ�.
                    dist[num] = dist[now_num] + 1;
                    q.push(num);
                }
            }
        }
    }
    if (dist.count(123456789) == 0){
        cout << -1 << endl;
    }
    else{
        cout << dist[123456789] << endl;
    }
    return 0;
}