#include <iomanip>
#include <iostream>

#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;

void addrecord(){
    print("\nAdd a record");
    string first = getStr("Enter first name: ");
    string middle = getStr("Enter middle name (optional): ");
    string last = getStr("Enter last name: ");
    string roll = getStr("Enter roll number: ");
    string year = getStr("Enter year level (number): ");
    string course = getStr("Enter course: ");
    string email = getStr("Enter email: ");
    string fullname = last + ", " + first + " " + middle;
    print ("Record added successfully!");
    
    return;
}


int main() {
    int x = 0;
    while (x == 0){
    print("Student Record Management System");
    print("1 - Add record(s)");
    print("2 - Delete record(s)");
    print("3 - Modify record(s)");
    print("4 - View record(s)");
    print("5 - Exit");
    string choice = getStr("Enter your choice: ");

    switch (choice[0]) {
        case '1':
            addrecord();
            break;
        case '2':
            break;
        case '3':
            print("Modify record(s)");
            break;
        case '4':
            print("View record(s)");
            break;
        case '5':
            x = 1;
            print("Exit");
            break;
        default:
            print("Invalid choice");
    }
    }
    return 0;
}
