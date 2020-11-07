#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

/* �մ��� �����ϱ� ���� ����ü */
/* �˾ƾ��� ���� = [ �մ��� ��ǥ , �մ��� ������ ��ǥ ] */
struct CUSTOMER {
    int x;
    int y;
    int Dest_x;
    int Dest_y;
};

/* ���ǿ� �´� �մ��� ã�� ���� ������ �����ϴ� ����ü */
/* �˾ƾ��� ���� = [ x��ǥ , y��ǥ , �Ÿ� , �մ��� ��ȣ ] */
struct INFO {
    int x;
    int y;
    int Dist;
    int Num;
};

int N, M, Fuel;
int Taxi_x, Taxi_y;
int MAP[25][25];
bool Visit[25][25];
CUSTOMER Customer[25 * 25];
bool Info_Cmp(INFO A, INFO B) {
    /* ���ǿ� �´� �մ��� ã�� ���ؼ� Vector�� �����ϱ� ���� ���� ����. */
    if (A.Dist <= B.Dist) {
        if (A.Dist == B.Dist) {
            if (A.x <= B.x) {
                if (A.x == B.x) {
                    if (A.y < B.y) {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

bool BFS(int a, int b, int c, int d, int Num){
    /* �մ��� �ִ� �Ÿ��� ���������� �̵���Ű�� ���� BFS Ž�� �Լ�. */
    memset(Visit, false, sizeof(Visit));
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(a, b), make_pair(0, Fuel)));
    Visit[a][b] = true;

    while (Q.empty() == 0) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Distance = Q.front().second.first;
        int Spare_Fuel = Q.front().second.second;
        Q.pop();

        /* �������� �����Ѵٸ� ? */
        /* ������ ���� ������ ���ǿ� �°� �缳��. */
        /* �ý��� ��ġ��, ���� �̵���Ų �մ��� ������ ��ġ�� �缳��. */
        if (x == c && y == d) {
            Fuel = Fuel - Distance;
            Fuel = Fuel + (Distance * 2);
            Taxi_x = x;
            Taxi_y = y;
            return true;
        }
        /* �� �̻� ���ᰡ ���ٸ� ? = �մ��� �� �̻� �̵���ų �� ����. */
        if (Spare_Fuel == 0) {
            return false;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + "1120"[i]-'1';
            int ny = y + "2011"[i]-'1';
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (MAP[nx][ny] != -1 && Visit[nx][ny] == false) {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(Distance + 1, Spare_Fuel - 1)));
                }
            }
        }
    }
    return false;
}

int Find_Shortest_Customer() {
    /* ���� �ý� ��ġ���� ���� ����� �մ��� ã�� ���� BFS�Լ�. */
    memset(Visit, false, sizeof(Visit));
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push(make_pair(make_pair(Taxi_x, Taxi_y), make_pair(0, Fuel)));
    Visit[Taxi_x][Taxi_y] = true;
    vector<INFO> V;
    /* ���� ���Ͱ� "���� ������ ������ ã�ư� �� �ִ� ��� �մԿ� ���� ����"�� ����. */
    while (Q.empty() == 0) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Distance = Q.front().second.first;
        int Spare_Fuel = Q.front().second.second;
        Q.pop();

        /* ���� 1 �̻��̶�� ���� �ش� ��ǥ�� �մ��� ������ �ǹ�. */
        /* ����, �ش� ��ǥ�� �ִ� �մԿ� ���� ������ Vector�� ����. */
        if (MAP[x][y] >= 1) {
            V.push_back({ x, y, Distance, MAP[x][y] });
        }
        if (Spare_Fuel == 0) {
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + "1120"[i] - '1';
            int ny = y + "2011"[i] - '1';
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {            
                if (MAP[nx][ny] != -1 && Visit[nx][ny] == false) {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(make_pair(nx, ny), make_pair(Distance + 1, Spare_Fuel - 1)));
                }
            }
        }
    }

    /* Vector�� Size = 0 �̶�� ���� ã�ư� �� �ִ� �մ��� ������ �ǹ�. */
    if (V.size() == 0) {
        return -1;
    }

    /* �װ� �ƴ϶��, �츮�� ã�� �� �Ѹ��� �մ��� ã�� ���ؼ� Vector�� ����. */
    /* �ش� �մ��� ���� �� �̻� �ش� ��ǥ�� �����Ƿ� �ʿ��� �� ����. */
    /* ���� �ý� ��ġ���� �ش� �մԱ��� ���µ� �� ���Ḹŭ ������ �� ���� ����. */
    sort(V.begin(), V.end(), Info_Cmp);
    MAP[V[0].x][V[0].y] = 0;
    Fuel = Fuel - V[0].Dist;
    return V[0].Num;
}

int main() {

    cin >> N >> M >> Fuel;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1) {
                MAP[i][j] = -1;
            }
            // �ʿ��� ������ ǥ�õǴ� 1�� -1�� ����.
        }
    }

    cin >> Taxi_x >> Taxi_y;
    // MAP�迭 ���� �ֻ���� (0,0)�̹Ƿ� ������
    Taxi_x--;
    Taxi_y--;
    
    for (int i = 1; i <= M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        Customer[i] = { a, b, c, d };
        MAP[a][b] = i;
        // �մ��� �ִ� ��ġ�� �� �մ��� ��ȣ�� ����
    }
    
    /* �ƹ��� ���Ƶ� �մ��� �� ��ŭ�� �����̸� �ȴ�. */
    /* ����, 0 ~ M�������� �ݺ�. */
    for (int i = 0; i < M; i++) {
        int Num = Find_Shortest_Customer();

        // ���᳻�� �� �� �ִ� �մ��� ���ٸ�
        if (Num == -1) {
            cout << -1 << "\n";
            return 0;
        }

        bool Move = BFS(Customer[Num].x, Customer[Num].y, Customer[Num].Dest_x, Customer[Num].Dest_y, Num);
        
        if (Move == false) {
            cout << -1 << "\n";
            return 0;
        }
    }
    cout << Fuel << "\n";
    return 0;
}