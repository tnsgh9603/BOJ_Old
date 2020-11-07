#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int city, bus;
int arr[101][101] = { 0, };
int way[111][111] = { 0, };
vector <int> V;
void floyd()
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
                if (arr[from][to] == 0 || arr[from][to] > arr[from][via] + arr[via][to]) {
                    //���������� ���������� �ٷΰ��� ���� ���ų�
                    //���� ���� �ͺ��� �������� ������ ���� ���� �� ���� ��� ������Ʈ
                    arr[from][to] = arr[from][via] + arr[via][to];
                    way[from][to] = via;
                }
            }
        }
    }
}
void Find_Route(int Start, int End)
{
    if (way[Start][End] == 0)
    {
        V.push_back(Start);
        V.push_back(End);
        return;
    }
    Find_Route(Start, way[Start][End]);
    V.pop_back();
    Find_Route(way[Start][End], End);
}
int main(){

    cin >> city >> bus;
    for (int i = 1; i <= bus; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (arr[from][to] == 0) {
            arr[from][to] = cost;
        }
        else // �̹� ��ΰ� �ִ� ��� �ּҰ� ����
            arr[from][to] = min(arr[from][to], cost);
    }

    floyd();

    for (int i = 1; i <= city; i++)
    {
        for (int j = 1; j <= city; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= city; i++)
    {
        for (int j = 1; j <= city; j++)
        {
            if (arr[i][j] == 0) cout << 0;
            else
            {
                V.clear();
                Find_Route(i, j);
                cout << V.size() << " ";
                for (int k = 0; k < V.size(); k++) {
                    cout << V.at(k) << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
