// lab03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct otrez {
    double left;
    double right;
};

double func(double x) {
    double ans = 7 * cos(x / 7) - (7 / x);
    return ans;
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

void hord_method(double a, double b) {
    double c = a - (func(a) / (func(b) - func(a))) * (b - a);
    if (func(c) == 0) {
        cout << "Koren nayden : " << c << endl;
    } else {
        cout << "koren ne nayden!" << endl;
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
    //    cout << "Selected segment is (" << v[s].left << " , " << v[s].right << ")\n";
    for (int i = 0; i < (int)v.size(); ++i) hord_method(v[i].left, v[i].right);
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
