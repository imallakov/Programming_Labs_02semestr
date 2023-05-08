#include <cmath>
#include <iostream>

#define eps 1e-4

using namespace std;

double func(double x) { return sin(x); }

double original_func(double x) { return -cos(x); }

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

double newton_leybnic(double a, double b) { return original_func(b) - original_func(a); }

int main() {
    double a, b, n, rect = 0, newleb = 0;
    cin >> a >> b >> n;
    do {
        n *= 2;
        double h = (abs((a - b)) / n);
        rect = rectangle_method(a, b, h);
        newleb = newton_leybnic(a, b);
        //        cout << rect << "   " << newleb << "   " << abs(rect - newleb) << endl;
    } while (abs(rect - newleb) > eps);

    cout << fixed << "N=" << n << "\nRectangle method = " << rect << "\nNewton-Leybnic method = " << newleb
         << endl;
}