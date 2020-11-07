#include <iostream>
#include <vector>
#include <algorithm> // sort �Լ�
#include <cmath> // cout.precision()
using namespace std;

int Parent[101];
double Answer;
vector<pair<double, double>> vec;
vector<pair<double, pair<int, int>>> Edge;

// �� ���ڸ����� �Ÿ��� ����ϴ� �Լ�
double Find_Distance(double x, double y, double xx, double yy) {
    double dx = (x - xx) * (x - xx);
    double dy = (y - yy) * (y - yy);
    double Dist = sqrt(dx + dy);
    return Dist;
}

// �θ��带 ã�� �Լ�
int Find_Parent(int a) {
    if (a == Parent[a]) {
        return a;
    }
    else return Parent[a] = Find_Parent(Parent[a]);
}

// �θ��尡 ������(����Ǿ� �ִ���) Ȯ���ϴ� �Լ�
bool Same_Parent(int A, int B) {
    A = Find_Parent(A);
    B = Find_Parent(B);
    if (A == B) {
        return true;
    }
    return false;
}
// ��峢�� ��ġ�� �Լ�
void Union(int A, int B) {
    A = Find_Parent(A);
    B = Find_Parent(B);
    if (A == B) {
        return;
    }
    if (B > A) {
        Parent[B] = A;
    }
    else {
        Parent[A] = B;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        double a, b;
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }    

    for (int i = 0; i < vec.size(); i++) {
        double x = vec[i].first;
        double y = vec[i].second;

        for (int j = i + 1; j < vec.size(); j++) {
            double xx = vec[j].first;
            double yy = vec[j].second;

            double Dist = Find_Distance(x, y, xx, yy);
            // �Ÿ��� (�����, ������) �� ����
            Edge.push_back(make_pair(Dist, make_pair(i, j)));
        }
    }

    // �ʱ�ȭ 
    for (int i = 0; i < N; i++) {
        Parent[i] = i;
    }

    // �Ÿ� ������ �������� ����
    sort(Edge.begin(), Edge.end());
    for (int i = 0; i < Edge.size(); i++) {
        double Cost = Edge[i].first;
        int Node1 = Edge[i].second.first;
        int Node2 = Edge[i].second.second;

        // ����Ǿ� ���� ������ ��ġ�� answer�� ����
        if (Same_Parent(Node1, Node2) == false) {
            Union(Node1, Node2);
            Answer = Answer + Cost;
        }
    }
    // �Ҽ��� 3��° �ڸ����� �ݿø��ؼ� 2�ڸ����� �����ؼ� ǥ���ϰڴ�.
    cout << fixed;
    cout.precision(2);

    cout << Answer << "\n";

    return 0;
}