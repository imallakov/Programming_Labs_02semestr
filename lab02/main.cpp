#include <iostream>

#include "kramer.h"
#include "matrix.h"

int main() {
    int t = 0, flag;
    flag = menu(&t);
    if (flag == 0) {
        if (t == 1) {
            matrix_equation();
        }
        if (t == 2) {
            std::cout << "Coming soon!)";
        }
        if (t == 3) {
            kramer();
        }
    } else {
        std::cout << "Error!";
    }
    return 0;
}