#include <iostream>
#include <stack>
#include <string>

using namespace std;

void operate(stack<string> adds, stack<char> opers) {
    bool first = true;
    while (!adds.empty()) {
        string s = adds.top();
        adds.pop();
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
        if (!opers.empty()) {
            if (!first || opers.top() == '-') cout << opers.top();
            opers.pop();
            first = false;
        }
        if (contains_number) {
            cout << coef;
            if (x) cout << "*";
        }
        if (x != 0) cout << "X";
        if (x > 1) cout << "^" << x;
    }
}

int main() {
    string s;
    cin >> s;
    stack<string> adds;
    stack<char> opers;
    if (s[0] == '-')
        opers.emplace('-');
    else
        opers.emplace('+');
    s += "+";
    string ss;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == '+' || s[i] == '-') {
            adds.emplace(ss);
            // operate(ss);
            ss = "";
            if (i < s.length() - 1) opers.emplace(s[i]);
        } else {
            ss += s[i];
        }
    }
    operate(adds, opers);
    return 0;
}