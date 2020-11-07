#include <iostream>
using namespace std;
int schedule[101], plug[101];
int main() {
    int N, K;
    cin >> N >> K; // N : ��Ƽ�� ���� ���� , K : ���� ��ǰ�� �� ��� Ƚ��
    
    // �����ǰ ��� ������ schedule�迭�� ����
    for (int i = 0; i < K; i++) {
        cin >> schedule[i];
    }

    int result = 0; // �÷��׸� ���� Ƚ���� �����ϴ� ����
    
    for (int i = 0; i < K; i++) {
        //plugedIn�� �ش� ��Ⱑ �����ִ��� Ȯ���ϴ� bool�� ����
        bool pluggedIn = false;
        //�ش� ��Ⱑ �����ִ��� Ȯ��
        for (int j = 0; j < N; j++) {
            // �����ִٸ� pluggedin�� true�� ����� break;
            if (plug[j] == schedule[i]) {
                pluggedIn = true;
                break;
            }
        }
        // ���������� continue
        if (pluggedIn) {
            continue;
        }
        // �� ����������
        //����ִ� ���� Ȯ��
        for (int j = 0; j < N; j++) {
            // ó�� plug�迭�� 0���� �ʱ�ȭ�Ǿ��ְ� schedule�迭�ȿ��� �ڿ����� ��������Ƿ� �̷��� ������.
            // �ش� ������ �������� ���� ���¶��
            if (!plug[j]) {
                // ���ۿ� �÷��׸� �Ȱ� pluggedin�� true�� ����
                plug[j] = schedule[i];
                pluggedIn = true;
                break;
            }
        }
        // �� ���ۿ� �ȾҴٸ� continue 
        if (pluggedIn) {
            continue;
        }
        //���� ���߿� �ٽ� ���ǰų� ������ ������ �ʴ� ��� ã��
        
        int idx, deviceIdx = -1; // �񱳿����� �������� ���� -1�� �ʱ�ȭ
        // ��� ���ۿ� ����
        for (int j = 0; j < N; j++) {
            int lastIdx = 0;
            // ���� �����ǰ�� �������� 
            for (int q = i + 1; q < K; q++) {
                // ������ �����ǰ�� �̹� �����ִٸ�
                if (plug[j] == schedule[q]) {
                    break;
                }
                lastIdx++;
            }
            // �̷��� �ϸ� �켱������ ������ ������� �ʴ� �����ǰ�� �����ִ� �÷��׸� ã�� �̰�
            // ������ ������� �ʴ� ��Ⱑ ������ ���� ���߿� �ٽ� ���Ǵ� �����ǰ�� �����ִ� �÷��׺��� �̴´�.
            if (lastIdx > deviceIdx) {
                idx = j; // idx -> �÷��׸� ���� ������ �ε���
                deviceIdx = lastIdx;
            }
        }
        // �÷��� ���� Ƚ�� ++
        result++;
        // �ռ� ã�� ��Ⱑ �����ִ� ���� ���� ���� �����̿��� ��⸦ ����
        plug[idx] = schedule[i];
    }
    cout << result << "\n";
    return 0;
}