#include <trieSearch.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// create a hashmap
void createHashMap(std::string content, std::unordered_map<std::string, std::string>& map) {
    std::vector<std::string> contacts;
    std::string contact;
    splitData(content, "\n", contacts);
    for (int i = 0; i < contacts.size(); i++) {
        splitData(contacts[i], ",", contact);
        map[contact[0]] = contacts[i];
    }
}
string* getRow(std::string content, std::string name) {
    std::vector<std::string> contacts;
    std::string contact;
    splitData(content, "\n", contacts);
    for (int i = 0; i < contacts.size(); i++) {
        splitData(contacts[i], ",", contact);
        if (contact[0] == name) {
            return &contacts[i];
        }
    }
    return NULL;
}