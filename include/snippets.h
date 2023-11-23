#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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

bool readFile(std::string fileName, std::string& content) {
    std::ifstream file;
    file.open(fileName);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
        return true;
    } else {
        return false;
    }
}
bool appendFile(std::string fileName, std::string content) {
    std::ofstream file;
    file.open(fileName, std::ios::app);
    if (file.is_open()) {
        file << content;
        file.close();
        return true;
    } else {
        return false;
    }
}
// create a function that splits a string
void splitData(std::string str, std::string delimiter, std::vector<std::string>& vec) {
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        // std::cout << str.substr(0, pos) << std::endl;
        token = str.substr(0, pos);
        vec.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    vec.push_back(str);
}