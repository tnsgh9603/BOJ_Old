#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define INF 200000000
using namespace std;

map<string, int> mp; 
vector<int> trip;
int arr[101][101]; // 내일로 티켓 없을때의 비용을 저장한 배열
int brr[101][101]; // 내일로 티켓을 구매했을 때 비용을 저장한 배열
int r, n;

void floyd() {  // 출발지와 목적지에 대한 최소비용 정리
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

bool ans() { //내일로 티켓을 샀을 때와 안 샀을 때의 가격차이 비교
    int aa = 0, bb = 0;
    for (int i = 0; i < trip.size() - 1; i++) {
        aa += arr[trip[i]][trip[i + 1]];
        bb += brr[trip[i]][trip[i + 1]];
    }
    return (bb + r < aa);
}
int main()
{
    // 변수 선언
    int x, y;
    string a, b, c;

    cin >> n >> r; // 한국에 있는 도시의 수(n)과 내일로 티켓의 가격(r) 입력 받음
    
    // 배열 초기화 작업
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                arr[i][j] = brr[i][j] = 0; // 출발지와 목적지가 같으면 0
            }
            else {
                arr[i][j] = brr[i][j] = INF; // 나머지 경우는 INF로 초기화
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cin >> a; // 한국에 있는 도시들을 입력 받음
        mp[a] = i; // map<string, int> mp;에 넣음, mp 컨테이너에 원소 (k,v)를 추가
    }

    cin >> x;

    for (int i = 0; i < x; i++) {
        cin >> a;
        trip.push_back(mp[a]); // 한국에 있는 도시들 중에서 여행할 도시를 vector<int> trip;에 넣음
    }

    cin >> x; // 교통수단의 수 입력받음

    for (int i = 0; i < x; i++) {
        cin >> a >> b >> c >> y; // 교통수단, 출발지, 도착지, 교통비
        arr[mp[b]][mp[c]] = min(y, arr[mp[b]][mp[c]]); // arr은 내일로 티켓이 없을때의 비용을 저장한 배열, 에 비용이 최소인것을 넣음
        arr[mp[c]][mp[b]] = min(y, arr[mp[b]][mp[c]]);
        if (a == "S-Train" || a == "V-Train") {  // 내일로 티켓을 사면 s-train, v-train 일 때 반값임
            brr[mp[b]][mp[c]] = min(y / 2, brr[mp[b]][mp[c]]);
            brr[mp[c]][mp[b]] = min(y / 2, brr[mp[b]][mp[c]]);
        }
        else if (a == "Mugunghwa" || a == "ITX-Saemaeul" || a == "ITX-Cheongchun") { // 내일로 티켓을 사면 각각은 무료
            brr[mp[b]][mp[c]] = 0;
            brr[mp[c]][mp[b]] = 0;
        }
        else {  // 나머지 교통수단에 대해서 정리
            brr[mp[b]][mp[c]] = min(y, brr[mp[b]][mp[c]]);
            brr[mp[c]][mp[b]] = min(y, brr[mp[b]][mp[c]]);
        }
    }
    floyd(); // 출발지와 목적지에 대한 최소비용 정리

    string answer = ans() ? "Yes" : "No"; //ans()가 참이면 yes, 아니면 no출력
    cout << answer;

    return 0;
}