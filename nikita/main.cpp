#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Enter path to file: ";
    std::cin >> str;
    std::ifstream fin(str);
    std::cout << "File path = " << str << "\nEnter the string that you want to search in the file: ";
    std::getline(std::cin, str);
    if (fin) {
        int flag = 0;
        while (fin) {
            std::string temp;
            std::getline(fin, temp);
            unsigned long long is_found = temp.find(str);
            if (is_found <= temp.length()) {
                flag = 1;
                std::cout << temp;
            }
        }
        if (flag == 0) {
            std::cout << "String wasn't found in the file!";
        }
        fin.close();
    } else {
        std::cout << "Error! Couldn't find/open the file!";
    }
    return 0;
}