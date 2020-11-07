#include <iostream>
#include <stdlib.h>
using namespace std;

// 오름차순으로 정렬할 때 사용하는 비교함수
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

    // 정렬 후
    for (int i = 0; i < input; i++)
        cout << array[i] << "\n";

    return 0;
}