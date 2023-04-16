// lab03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <iostream>
#include <vector>
#define EPS (1e-7)
#define N 7
using namespace std;

struct otrez {
    double left;
    double right;
};

double func(double x) {
    double ans = N * cos(x / N) - (N / x);
    return ans;
    //    return x * x * x * x - 16 * x - 64;
}

double proiz_func(double x) {
    double ans = (-1 * sin(x / N)) + (N / (x * x));
    return ans;
    //    return 4 * x * x * x - 16;
}

vector<otrez> otr(double a, double b, double h) {
    vector<otrez> v;
    double i = a;
    while (i <= b - h) {
        if (abs(i) - 0 < 10e-4) i = 0;
        double left = i;
        double right = i + h;
        //        cout << left << " " << right << " " << h << endl;
        if (func(left) * func(right) < 0) {
            otrez k = {0, 0};
            k.left = left;
            k.right = right;
            v.push_back(k);
        }
        i += h;
    }
    return v;
}

double get_start_node(double a, double b) {
    double ans = 0;
    int flag = 0;
    for (int i = (int)a + 1; i <= (int)b && flag == 0; ++i) {
        if (func(i) * func(i - 1) < 0) {
            ans = (double)i;
            flag = 1;
        }
    }
    return ans;
}

void nyuton(double a, double b, double m) {
    double prev, x = get_start_node(a, b);
    cout << "Start point = " << x << endl;
    do {
        prev = x;
        x = prev - (func(prev) / proiz_func(prev));
        cout << "x_n+1 = " << x << "    x_n = " << prev << "     f = " << abs(abs(x) - abs(prev)) << endl;
    } while (abs(abs(x) - abs(prev)) > EPS);
    cout << "Koren nayden : x=" << x << endl;
}

void pol_del(double a, double b, double m) {
    int iter = 0;
    double left = a, right = b, f, x;
    do {
        x = (left + right) / 2;
        f = func(x);
        if (f * func(left) < 0)
            right = x;
        else
            left = x;
        iter++;
    } while (fabs(f) > EPS && iter < 20000);
    if (fabs(f) < EPS)
        cout << "Koren nayden:  x = " << x << endl;
    else {
        cout << "Koordinaty otrezka: [ " << left << " ; " << right << " ]\n";
    }
}

void hord_method(double a, double b, double m) {
    double h = (double)(b - a) / m;

    double c = a - (func(a) / (func(b) - func(a))) * (b - a);
    if (abs(func(c)) <= EPS) {
        cout << "Koren nayden:  x = " << c << endl;
    } else {
        for (double i = a + h; i <= b; i += h) {
            if (func(a) * func(b) < 0) {
                cout << "Koordinaty otrezka: [ " << i << " ; " << i - h << " ]\n";
                break;
            }
        }
    }
}

int main() {
    int a, b, m;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter the value of m: ";
    cin >> m;

    vector<otrez> v;
    v = otr(a, b, (double)(b - a) / m);

    for (int i = 0; i < (int)v.size(); ++i) {
        cout << i << ".\t(" << v[i].left << " , " << v[i].right << ")" << endl;
    }
    int s = -1;
    while (s < 0 || s >= (int)v.size()) {
        cout << "Select one of the segments and enter its number: ";
        cin >> s;
    }
    cout << "Selected segment is (" << v[s].left << " , " << v[s].right << ")\n";
    cout << "=======HORD METHOD=======\n";
    hord_method(v[s].left, v[s].right, m);

    cout << "=METHOD POLOVINNOGO DELENIYA=\n";
    pol_del(v[s].left, v[s].right, m);

    cout << "===METHOD NYUTONA===\n";
    nyuton(v[s].left, v[s].right, m);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing
//   code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
