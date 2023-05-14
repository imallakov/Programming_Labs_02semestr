#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cout << "Vvedite kolichestvo elementov massiva: ";
    cin >> n;
    int a[n + 1];
    cout << "Vvedite elementy massiva razmerom " << n << ":\n";
    for (int i = 0; i < n; ++i) cin >> a[i];
    int max = INT32_MIN;
    set<int> s;
    for (int j = 0; j < n; ++j) {
        if (s.find(a[j]) != s.end()) {
            if (a[j] > max) max = a[j];
        }
        s.emplace(a[j]);
    }
    cout << "Answer : " << max << endl;
    return 0;
}