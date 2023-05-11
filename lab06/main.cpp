#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n = 7;
    stack<int> first, second;
    cout << "Enter the coefficients in the followind order:\n";
    cout << "K_0*X_7 + K_1*X_6 + K_2*X_5 + K_3*X_4 + K_4*X_3 + K_5*X_2 + K_6*X_1 + K_7*X_0\n";
    cout << "\nFirst Polynom:\n";
    for (int i = 0; i <= n; ++i) {
        int a;
        cin >> a;
        first.push(a);
    }
    cout << "\nSecond Polynom:\n";
    for (int i = 0; i <= n; ++i) {
        int a;
        cin >> a;
        second.push(a);
    }
    int i = 0;
    while (!first.empty()) {
        int temp = first.top() + second.top();
        if (i != 0 && temp >= 0) cout << " + ";
        if (temp < 0) cout << " - ";
        cout << abs(temp) << "x^" << i;
        i++;
        first.pop();
        second.pop();
    }
    return 0;
}