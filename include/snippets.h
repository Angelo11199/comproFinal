#include <conio.h>

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
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
// gets a number from the user
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
// reads the file and returns in string content
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
    } else
        return false;
}
// adds data to the file. returns true if successful
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
bool deleteRow(string fileName, string rowName) {
    std::string contents;
    readFile(fileName, contents);
    std::vector<std::string> data;
    splitData(contents, "\n", data);
    // loop through the data and add the indexes element to the hashmap
    for (int i = 0; i < data.size() - 1; i++) {
        std::vector<std::string> row;
        splitData(data[i], ",", row);
        if (row[0] == rowName) {
            data.erase(data.begin() + i);
            std::string newContent;
            for (int i = 0; i < data.size(); i++) {
                newContent += data[i] + "\n";
            }
            std::ofstream file;
            file.open(fileName);
            if (file.is_open()) {
                file << newContent;
                file.close();
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}
// splits the string into a vector
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
std::unordered_map<std::string, std::vector<std::string>>
    csvData;

std::vector<std::string> getRow(const std::string& value) {
    std::vector<std::string> contacts;
    // read csvData and check if the name is in the csvData
    if (csvData.find(value) != csvData.end()) {
        return csvData[value];
    }
    return {};
}

void init(std::string content, std::unordered_map<std::string, std::vector<std::string>>& csvData, const std::vector<int>& indexes) {
    std::string contents;
    readFile(content, contents)
        ? print(content + " read successfully.")
        : print(content + " read failed.");
    std::vector<std::string> data;
    splitData(contents, "\n", data);
    std::vector<std::string> fields;
    // loop through the data and add the indexes element to the hashmap
    for (int i = 0; i < data.size() - 1; i++) {
        std::vector<std::string> row;
        splitData(data[i], ",", row);
        for (int j = 0; j < indexes.size(); j++) {
            print(indexes[j]);
            csvData[row[indexes[j]]] = row;
        }
    }
    print("Initializing...");
    print("Initialization complete.");
}
