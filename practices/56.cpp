#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Vvedite razmer kvadratnoy matrisy: ";
    cin >> n;
    int a[n + 1][n + 1];
    cout << "Vvedite elementy matrisy razmerom " << n << "x" << n << ":\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    int max = INT32_MIN;

    for (int i = 0; i < n; ++i) {
        int temp_sum = 0;
        for (int j = 0; j < n; ++j) {
            temp_sum += a[i][j];
        }
        if (temp_sum > max) max = temp_sum;
    }

    cout << "Answer : " << max << endl;
    return 0;
}