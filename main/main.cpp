#include <iomanip>
#include <iostream>

#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;

int main() {
    print("Student Record Management System");
    print("1 - Add record(s)");
    print("2 - Delete record(s)");
    print("3 - Modify records");
    print("4 - View records");
    print("5 - Exit");
    string choice = getStr("Enter your choice: ");
    switch (choice[0]) {
        case '1':
            print("Add record(s)");
            break;
        case '2':
            print("Delete record(s)");
            break;
        case '3':
            print("Modify record(s)");
            break;
        case '4':
            print("View record(s)");
            break;
        case '5':
            print("Exit");
            break;
        default:
            print("Invalid choice");
    }


    return 0;
}