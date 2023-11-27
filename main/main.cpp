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
        while (roll.length() != 9){
            print ("Invalid roll number, try again.");
            roll = getStr("Enter roll number: ");
        }
    string phone = getStr("Enter phone number: ");
        while (phone.length() != 11){
            print ("Invalid phone number, try again.");
            phone = getStr("Enter phone number: ");
        }
    string year = getStr("Enter year level (number): ");
        switch (year[0]) {
            case '1':
                year = "1st";
                break;
            case '2':
                year = "2nd";
                break;
            case '3':
                year = "3rd";
                break;
            default:
                year = year + "th";
        }
    string course = getStr("Enter course: ");
    string email = getStr("Enter email: ");
    string fullname = last + ", " + first + " " + middle;
    print ("Record added successfully!");
    //add record to file
    //add if not for unsuccessful
    return;
}

void deleterecord(){
    print("Delete a record");

}

void modifyrecord(){
    print ("Modify a record");

}

void viewrecord(){
    print("Viewing records...");

}

int main() {
    int x = 0;
    while (x == 0){
    print("\nStudent Record Management System");
    print("A - Add record");
    print("D - Delete record");
    print("M - Modify record");
    print("V - View record");
    print("Q - QUIT");
    string choice = getStr("Enter your choice: ");

    switch (tolower(choice[0])) {
        case 'a':
            addrecord();
            break;
        case 'd':
            deleterecord();
            break;
        case 'm':
            modifyrecord();
            break;
        case 'v':
            viewrecord();
            break;
        case 'q':
            x = 1;
            print("Exit");
            break;
        default:
            print("Invalid choice");
    }
    return 0;
    }
}
