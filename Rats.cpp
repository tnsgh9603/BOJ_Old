#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double n1, n2, n12;
    cin >> n1 >> n2 >> n12;
    cout << floor(((n1 + 1) * (n2 + 1) / (n12 + 1)) - 1);
}
