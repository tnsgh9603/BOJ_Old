#include <iostream>
#include <algorithm>
using namespace std;

int city, bus;
int arr[101][101] = { 0, };
void floyd(void)
{
    for (int via = 1; via <= city; via++)
    {
        for (int from = 1; from <= city; from++)
        {
            if (arr[from][via] == 0) { //���������� ���������� �� �� ���� ���� ����
                continue;
            }
            for (int to = 1; to <= city; to++)
            {
                if (arr[via][to] == 0 || from == to) // ���������� ���������� �� �� ���� ���, ������ = �������� ���� ���x
                    continue;
                if (arr[from][to] == 0 || arr[from][to] > arr[from][via] + arr[via][to]){
                    //���������� ���������� �ٷΰ��� ���� ���ų�
                    //���� ���� �ͺ��� �������� ������ ���� ���� �� ���� ��� ������Ʈ
                    arr[from][to] = arr[from][via] + arr[via][to];
                }
            }
        }
    }
}
int main(void)
{
    cin >> city >> bus;
    for (int i = 1; i <= bus; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (arr[from][to] == 0) {
            arr[from][to] = cost;
        }
        else //�̹� ��ΰ� �ִ� ��� �ּҰ� ����
            arr[from][to] = min(arr[from][to], cost);
    }
    floyd();
    for (int i = 1; i <= city; i++)
    {
        for (int j = 1; j <= city; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
