#include <iostream>
#include <string>
// prints in a new line
template <typename T>
void print(T Value) {
        std::cout << Value << std::endl;
}
// Prints in the same line
template <typename U>
void printLn(U s) {
    std::cout << s;
};
double getNum(std::string prompt = "") {
    std::string num;
    char* p;
    do {
        std::cout << prompt;
        std::cin >> num;
        double convertedNum = strtod(num.c_str(), &p);
        if (*p) {
            std::cout << "Invalid input" << std::endl;
        } else {
            std::cin.ignore();
            return convertedNum;
        }
    } while (true);
    return 0;
}
std::string getStr(std::string prompt = "") {
    std::string s;
    std::cout << prompt;
    // std::cin.ignore();
    getline(std::cin, s);
    return s;
}
