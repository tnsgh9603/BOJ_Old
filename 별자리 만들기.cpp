#include <iostream>
#include <vector>
#include <algorithm> // sort 함수
#include <cmath> // cout.precision()
using namespace std;

int Parent[101];
double Answer;
vector<pair<double, double>> vec;
vector<pair<double, pair<int, int>>> Edge;

// 두 별자리간의 거리를 계산하는 함수
double Find_Distance(double x, double y, double xx, double yy) {
    double dx = (x - xx) * (x - xx);
    double dy = (y - yy) * (y - yy);
    double Dist = sqrt(dx + dy);
    return Dist;
}

// 부모노드를 찾는 함수
int Find_Parent(int a) {
    if (a == Parent[a]) {
        return a;
    }
    else return Parent[a] = Find_Parent(Parent[a]);
}

// 부모노드가 같은지(연결되어 있는지) 확인하는 함수
bool Same_Parent(int A, int B) {
    A = Find_Parent(A);
    B = Find_Parent(B);
    if (A == B) {
        return true;
    }
    return false;
}
// 노드끼리 합치는 함수
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
            // 거리와 (출발점, 시작점) 을 넣음
            Edge.push_back(make_pair(Dist, make_pair(i, j)));
        }
    }

    // 초기화 
    for (int i = 0; i < N; i++) {
        Parent[i] = i;
    }

    // 거리 순으로 오름차순 정렬
    sort(Edge.begin(), Edge.end());
    for (int i = 0; i < Edge.size(); i++) {
        double Cost = Edge[i].first;
        int Node1 = Edge[i].second.first;
        int Node2 = Edge[i].second.second;

        // 연결되어 있지 않으면 합치고 answer값 갱신
        if (Same_Parent(Node1, Node2) == false) {
            Union(Node1, Node2);
            Answer = Answer + Cost;
        }
    }
    // 소수점 3번째 자리에서 반올림해서 2자리까지 고정해서 표현하겠다.
    cout << fixed;
    cout.precision(2);

    cout << Answer << "\n";

    return 0;
}