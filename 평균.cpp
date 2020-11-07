#include <iostream>
#include <memory.h>
#include <stdlib.h>
using namespace std;
int main() {
    int subject_number, best_score = 0, sum = 0;
    cin >> subject_number;
    int subject_score[1005];
    for (int i = 1; i <= subject_number; i++) {
        cin >> subject_score[i];
        sum = sum + subject_score[i];
        if (subject_score[i] > best_score) {
            best_score = subject_score[i];
        }
    }
    double ratio = (double)100 / (double)best_score;
    double average = (double)sum / (double)subject_number * (double)ratio;
    //cout.precision(10);
    cout << average;
    return 0;
}
