#include <iostream>
#include <stdlib.h>
using namespace std;

// ������������ ������ �� ����ϴ� ���Լ�
int static compare(const void* first, const void* second)
{
    if (*(int*)first > * (int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main()
{
    int input;
    cin >> input;
    int* array = new int[input];
    for (int i = 0; i < input; i++) {
        cin >> array[i];
    }


    qsort(array, input, sizeof(int), compare);

    // ���� ��
    for (int i = 0; i < input; i++)
        cout << array[i] << "\n";

    return 0;
}