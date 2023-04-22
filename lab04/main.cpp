#include <cmath>
#include <iostream>

using namespace std;

double func(double x) { return sin(x); }

double rectangle_method(double a, double b, double h) {
    double ans = 0;
    double x = a + h;
    while (x <= b) {
        ans += func((x - h + x) / 2.0) * h;
        x += h;
    }
    return ans;
}

double trapezium_method(double a, double b, double h) {
    double ans = 0;
    double x = a + h;
    while (x <= b) {
        ans += ((func(x - h) + func(x)) / 2.0) * h;
        x += h;
    }
    return ans;
}

double simpson_method(double a, double b, double h) {
    double ans = 0;
    double x = a + h;
    while (x <= b) {
        ans += (func(x - h) + 4 * func((x - h + x) / 2) + func(x)) / 6.0;
        x += h;
    }
    return ans;
}

int main() {
    double a, b, n;
    cin >> a >> b >> n;
    double h = (abs(abs(a) - abs(b)) / n);
    cout << "" << h << endl;
    cout << rectangle_method(a, b, h);
}