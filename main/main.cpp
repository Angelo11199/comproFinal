#include "../include/snippets.h"
using namespace std;
#include <conio.h>

#include <iomanip>
#include <iostream>
#include <vector>

void addrecord() {
    system("cls");
    print("--------------------------------");
    print("ADD A RECORD");
    print("--------------------------------");
    string last = getStr("Enter last name: ");
    string first = getStr("Enter first name: ");
    string middle = getStr("Enter middle name: ");
    string RN = getStr("Enter roll number: ");
    while (RN.length() != 9) {
        print("Invalid student number, try again.");
        RN = getStr("Enter student number: ");
    }
    string CN = getStr("Enter contact number: ");
    while (CN.length() != 11 && CN.length() != 7) {
        print("Invalid contact number, try again.");
        CN = getStr("Enter contact number: ");
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
    string record = RN + SEPERATOR + FN + SEPERATOR + CN + SEPERATOR + year + SEPERATOR + course + SEPERATOR + email;
    bool isSuccess = appendFile("record.csv", record);
    if (isSuccess) {
        print("Contact added successfully!");
        vector<string> row = {RN, last, first, middle, CN, year, course, email};
        csvData[RN] = row;
        csvData[last] = row;
    } else
        print("Failed to add contact!");
    pauseProgram();
}

void deleterecord() {
    system("cls");
    print("--------------------------------");
    print("DELETE A RECORD");
    print("--------------------------------");
    print("[1] - Roll number");
    print("[2] - Last name");
    print("--------------------------------");
    string Choice1 = getStr("Enter your choice: ");
    switch(Choice1[0]){
        case '1':{
            string SN = getStr("Enter roll number: ");
            vector<string> result = getRow(SN);
            deleteRow("contacts.csv", result[0]);
            print("Contact added successfully!");
            break;
        }
        case '2':{
            string last = getStr("Enter last name: ");
            vector<string> result = getRow(last);
            deleteRow("contacts.csv", result[0]);
            print("Contact added successfully!");
            break;
        }
        default:{
            print("Invalid Choice");
        }
    }
    pauseProgram();
    
}

void modifyrecord() {
    print("Modify a record");
}

void viewrecord() {
    print("Viewing records...");
}

int main() {
    std::vector<int> indexes = {0, 1};
    init("record.csv", csvData, indexes);
    bool exit = false;
    while (!exit) {
        system("cls");
        print("--------------------------------");
        print("Student Record Management System");
        print("--------------------------------");
        print("[1] - Add record");
        print("[2] - Delete record");
        print("[3] - Modify record");
        print("[4] - View record");
        print("[5] - QUIT");
        print("--------------------------------");
        string choice = getStr("Enter your choice: ");

        switch (choice[0]) {
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
