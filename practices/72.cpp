#include <iomanip>
#include <iostream>
#include <random>
#include <set>

#define N 20

using namespace std;

int main() {
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> random_number(-200, 200);  // range in [-2000;2000]
    int A[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = (int)random_number(rng);
            cout << setw(6) << A[i][j];
        }
        cout << endl;
    }
    int ans = 0;
    for (int j = 0; j < N; ++j) {
        set<int> s;
        bool flag = true;
        for (int i = 0; i < N && flag; ++i) {
            if (s.find(A[i][j]) != s.end()) {
                flag = false;
            }
            s.emplace(A[i][j]);
        }
        if (flag) {
            ++ans;
        }
    }
    cout << "Answer : " << ans << endl;
    return 0;
}