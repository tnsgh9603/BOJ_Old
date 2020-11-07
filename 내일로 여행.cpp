#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define INF 200000000
using namespace std;

map<string, int> mp; 
vector<int> trip;
int arr[101][101]; // ���Ϸ� Ƽ�� �������� ����� ������ �迭
int brr[101][101]; // ���Ϸ� Ƽ���� �������� �� ����� ������ �迭
int r, n;

void floyd() {  // ������� �������� ���� �ּҺ�� ����
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
                if (brr[i][k] + brr[k][j] < brr[i][j])
                    brr[i][j] = brr[i][k] + brr[k][j];
            }
        }
    }
}

bool ans() { //���Ϸ� Ƽ���� ���� ���� �� ���� ���� �������� ��
    int aa = 0, bb = 0;
    for (int i = 0; i < trip.size() - 1; i++) {
        aa += arr[trip[i]][trip[i + 1]];
        bb += brr[trip[i]][trip[i + 1]];
    }
    return (bb + r < aa);
}
int main()
{
    // ���� ����
    int x, y;
    string a, b, c;

    cin >> n >> r; // �ѱ��� �ִ� ������ ��(n)�� ���Ϸ� Ƽ���� ����(r) �Է� ����
    
    // �迭 �ʱ�ȭ �۾�
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                arr[i][j] = brr[i][j] = 0; // ������� �������� ������ 0
            }
            else {
                arr[i][j] = brr[i][j] = INF; // ������ ���� INF�� �ʱ�ȭ
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> a; // �ѱ��� �ִ� ���õ��� �Է� ����
        mp[a] = i; // map<string, int> mp;�� ����, mp �����̳ʿ� ���� (k,v)�� �߰�
    }

    cin >> x;

    for (int i = 0; i < x; i++) {
        cin >> a;
        trip.push_back(mp[a]); // �ѱ��� �ִ� ���õ� �߿��� ������ ���ø� vector<int> trip;�� ����
    }

    cin >> x; // ��������� �� �Է¹���

    for (int i = 0; i < x; i++) {
        cin >> a >> b >> c >> y; // �������, �����, ������, �����
        arr[mp[b]][mp[c]] = min(y, arr[mp[b]][mp[c]]); // arr�� ���Ϸ� Ƽ���� �������� ����� ������ �迭, �� ����� �ּ��ΰ��� ����
        arr[mp[c]][mp[b]] = min(y, arr[mp[b]][mp[c]]);
        if (a == "S-Train" || a == "V-Train") {  // ���Ϸ� Ƽ���� ��� s-train, v-train �� �� �ݰ���
            brr[mp[b]][mp[c]] = min(y / 2, brr[mp[b]][mp[c]]);
            brr[mp[c]][mp[b]] = min(y / 2, brr[mp[b]][mp[c]]);
        }
        else if (a == "Mugunghwa" || a == "ITX-Saemaeul" || a == "ITX-Cheongchun") { // ���Ϸ� Ƽ���� ��� ������ ����
            brr[mp[b]][mp[c]] = 0;
            brr[mp[c]][mp[b]] = 0;
        }
        else {  // ������ ������ܿ� ���ؼ� ����
            brr[mp[b]][mp[c]] = min(y, brr[mp[b]][mp[c]]);
            brr[mp[c]][mp[b]] = min(y, brr[mp[b]][mp[c]]);
        }
    }
    floyd(); // ������� �������� ���� �ּҺ�� ����

    string answer = ans() ? "Yes" : "No"; //ans()�� ���̸� yes, �ƴϸ� no���
    cout << answer;

    return 0;
}