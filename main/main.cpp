#include "../include/snippets.h"
using namespace std;
#include <iomanip>
#include <iostream>
#include <conio.h>
#include <vector>

void addrecord(){
    system("cls");
    print("\nAdd a record");
    string last = getStr("Enter last name: ");
    string first = getStr("Enter first name: ");
    string middle = getStr("Enter middle name: ");
    string SN = getStr("Enter student number: ");
        while (SN.length() != 9){
            print ("Invalid student number, try again.");
            SN = getStr("Enter student number: ");
        }
    string CN = getStr("Enter contact number: ");
        while (CN.length() != 11 || CN.length() != 7){
            print ("Invalid phone number, try again.");
            CN = getStr("Enter phone number: ");
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
    string FN = last + ", " + first + " " + middle;
    string record = SN + "|" + FN  + " | " + CN + " | " + year + " | " + course + " | " + email;
    bool isSuccess = appendFile("record.csv", record);
    if (isSuccess) {
        print("Contact added successfully!");
        vector<string> row = {SN, last, first, middle, CN, year, course, email};
        csvData[SN] = row;
    } else
        print("Failed to add contact!");
    pauseProgram();
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
    std::vector<int> indexes = {0, 1};
    init("record.cvs", csvData, indexes);
    bool exit = false;
    while (!exit) {
        system("cls");
        print("Student Record Management System");
        print("[1] - Add record");
        print("[2] - Delete record");
        print("[3] - Modify record");
        print("[4] - View record");
        print("[5] - QUIT");
        string choice = getStr("Enter your choice: ");

        switch (tolower(choice[0])) {
            case '1':
                addrecord();
                break;
            case '2':
                deleterecord();
                break;
            case '3':
                modifyrecord();
                break;
            case '4':
                viewrecord();
                break;
            case '5':
                exit = true;
                print("Exit");
                break;
            default:
                print("Invalid choice");
        }
    return 0;
    }
}
