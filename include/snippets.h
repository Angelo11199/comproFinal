#include <fstream>
#include <iostream>
#include <string>
// prints in a new line
#define MAX 100
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

std::string* searchCMS(std::string value, int skip = 0) {
    // todo: search for value in cms array
    // todo: use fibonacci search

    std::string cms[5] = {"wordpress", "joomla", "drupal", "magento", "shopify"};
    static std::string result[5];
    for (int i = 0; i < 5; i++) {
        result[i] = cms[i];
    }
    return result;
}

std::string* seperateFile(std::string text, int skip = 0) {
    static std::string result[MAX];
    // seperate text using regex
    for (int i = 0; i < MAX; i++) {
        result[i] = "hello";
    }
    return result;
}