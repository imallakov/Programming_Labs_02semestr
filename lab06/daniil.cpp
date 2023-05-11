#include <iostream>
#include <string>

using namespace std;

void operate(string s) {
    int coef = 1, x = 0, temp = 0;
    bool contains_number = false;
    s += "*";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            temp *= 10;
            temp += (s[i] - 48);
            contains_number = true;
        } else {
            if (s[i] == 'X') ++x;
            coef *= max(temp, 1);
            temp = 0;
        }
    }
    if (contains_number) {
        cout << coef;
        if (x) cout << "*";
    }
    if (x != 0) cout << "X";
    if (x > 1) cout << "^" << x;
}

int main() {
    string s = "";
    cin >> s;
    s += "+";
    string ss = "";
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == '+' || s[i] == '-') {
            operate(ss);
            ss = "";
            if (i < s.length() - 1) cout << s[i];
        } else {
            ss += s[i];
        }
    }
}