#include <iostream>
using namespace std;
int schedule[101], plug[101];
int main() {
    int N, K;
    cin >> N >> K; // N : 멀티탭 구멍 갯수 , K : 전기 용품의 총 사용 횟수
    
    // 전기용품 사용 순서를 schedule배열에 저장
    for (int i = 0; i < K; i++) {
        cin >> schedule[i];
    }

    int result = 0; // 플러그를 뽑은 횟수를 저장하는 변수
    
    for (int i = 0; i < K; i++) {
        //plugedIn은 해당 기기가 꽂혀있는지 확인하는 bool형 변수
        bool pluggedIn = false;
        //해당 기기가 꽂혀있는지 확인
        for (int j = 0; j < N; j++) {
            // 꽂혀있다면 pluggedin을 true로 만들고 break;
            if (plug[j] == schedule[i]) {
                pluggedIn = true;
                break;
            }
        }
        // 꽂혀있으면 continue
        if (pluggedIn) {
            continue;
        }
        // 안 꽂혀있으면
        //비어있는 구멍 확인
        for (int j = 0; j < N; j++) {
            // 처음 plug배열은 0으로 초기화되어있고 schedule배열안에는 자연수만 들어있으므로 이렇게 가능함.
            // 해당 구멍이 꽂혀있지 않은 상태라면
            if (!plug[j]) {
                // 구멍에 플러그를 꽂고 pluggedin을 true로 만듬
                plug[j] = schedule[i];
                pluggedIn = true;
                break;
            }
        }
        // 빈 구멍에 꽂았다면 continue 
        if (pluggedIn) {
            continue;
        }
        //가장 나중에 다시 사용되거나 앞으로 사용되지 않는 기기 찾고
        
        int idx, deviceIdx = -1; // 비교연산이 편해지기 위해 -1로 초기화
        // 모든 구멍에 대해
        for (int j = 0; j < N; j++) {
            int lastIdx = 0;
            // 다음 전기용품의 순서부터 
            for (int q = i + 1; q < K; q++) {
                // 이후의 전기용품이 이미 꽂혀있다면
                if (plug[j] == schedule[q]) {
                    break;
                }
                lastIdx++;
            }
            // 이렇게 하면 우선적으로 앞으로 사용하지 않는 전기용품이 꽂혀있는 플러그를 찾아 뽑고
            // 앞으로 사용하지 않는 기기가 없으면 가장 나중에 다시 사용되는 전기용품이 꽂혀있는 플러그부터 뽑는다.
            if (lastIdx > deviceIdx) {
                idx = j; // idx -> 플러그를 뽑을 구멍의 인덱스
                deviceIdx = lastIdx;
            }
        }
        // 플러그 뽑은 횟수 ++
        result++;
        // 앞서 찾은 기기가 꽂혀있던 곳에 현재 꽂을 예정이였던 기기를 꽂음
        plug[idx] = schedule[i];
    }
    cout << result << "\n";
    return 0;
}