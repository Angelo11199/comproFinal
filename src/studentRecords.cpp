#include "../include/snippets.h"
using namespace std;
#include <conio.h>

#include <iomanip>
#include <iostream>
#include <vector>
const string studentRecordFile = "studentRecords.csv";
void addrecord() {
    // system("cls");
    string last = getStr("Enter last name: ");
    string first = getStr("Enter first name: ");
    string middle = getStr("Enter middle name: ");
    string rollNumber = getStr("Enter roll number: ");
    while (rollNumber.length() != 9) {
        print("Invalid roll number, try again.");
        rollNumber = getStr("Enter roll number: ");
    }
    string contact = getStr("Enter contact number: ");
    while (contact.length() != 11 && contact.length() != 7) {
        print("Invalid contact number, try again.");
        contact = getStr("Enter contact number: ");
    }
    int year = getNum("Enter year level (number): ");
    string yearLevel;
    switch (year) {
        case 1:
            yearLevel = "1st";
            break;
        case 2:
            yearLevel = "2nd";
            break;
        case 3:
            yearLevel = "3rd";
            break;
        default:
            yearLevel = to_string(year) + "th";
    }
    string course = getStr("Enter course: ");
    string email = getStr("Enter email: ");
    string fullName = last + SEPERATOR + first + SEPERATOR + middle;
    string record = rollNumber + SEPERATOR + fullName + SEPERATOR + contact + SEPERATOR + yearLevel + SEPERATOR + course + SEPERATOR + email + "\n";
    bool isSuccess = appendFile(studentRecordFile, record);
    if (isSuccess) {
        print("Contact added successfully!");
        vector<string> row = {rollNumber, last, first, middle, contact, yearLevel, course, email};
        csvData[rollNumber] = row;
        csvData[last] = row;
    } else
        print("Failed to add contact!");
    pauseProgram();
}

void deleterecord() {
    // system("cls");
    print("--------------------------------");
    print("DELETE A RECORD");
    print("--------------------------------");
    print("[1] - Roll number");
    print("[2] - Last name");
    print("--------------------------------");
    string choice = getStr("Enter your choice: ");
    switch (choice[0]) {
        case '1': {
            string RN = getStr("Enter roll number: ");
            vector<string> result = getRow(RN);
            deleteRow(studentRecordFile, result[0]);
            print("Record deleted successfully!");
            break;
        }
        case '2': {
            string last = getStr("Enter last name: ");
            vector<string> result = getRow(last);
            deleteRow(studentRecordFile, result[1]);
            print("Contact deleted successfully!");
            break;
        }
        default: {
            print("Invalid Choice");
        }
    }
    pauseProgram();
}

bool updateProcess(string noun, vector<string> result, int index) {
    string newValue = getStr("Enter new" + noun + ":");
    bool isSuccess = updateRow(studentRecordFile, result[0], newValue, index);
    result[index] = isSuccess ? newValue : result[index];
    csvData[result[0]] = result;
    csvData[result[1]] = result;

    return isSuccess;
}

void modifyrecord() {
    // system("cls");
    bool isSuccess = false;
    string newValue;
    print("--------------------------------");
    print("MODIFY A RECORD");
    print("--------------------------------");
    print("[1] - Roll number");
    print("[2] - Last name");
    print("--------------------------------");
    string choice = getStr("Enter your choice: ");
    switch (choice[0]) {
        case '2':
        case '1': {
            string rollNumber = getStr("Enter record: ");
            vector<string> result = getRow(rollNumber);
            // system("cls");
            if (result.empty()) {
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");
                pauseProgram();
                break;
            } else {
                // system("cls");
                print("--------------------------------");
                print("PICK THE SUBJECT YOU WANT TO MODIFY");
                print("--------------------------------");
                print("[1] - Roll Number: " + result[0] + "\n[2] - Last Name: " + result[1] + "\n[3] - First Name: " + result[2] + "\n[4] - Middle Name: " + result[3] + "\n[5] - Contact Number: " + result[4] + "\n[6] - Year Level: " + result[5] + "\n[7] - Course: " + result[6] + "\n[8] - Email: " + result[7]);
                print("--------------------------------");
            }
            while (!isSuccess) {
                string choice = getStr("Enter your choice: ");
                switch (choice[0]) {
                    case '1': {
                        isSuccess = updateProcess(" Roll number", result, 0);
                        break;
                    }
                    case '2': {
                        isSuccess = updateProcess(" Last name", result, 1);
                        break;
                    }
                    case '3': {
                        isSuccess = updateProcess(" First name", result, 2);
                        break;
                    }
                    case '4': {
                        isSuccess = updateProcess(" Middle name", result, 3);
                        break;
                    }
                    case '5': {
                        isSuccess = updateProcess(" Contact number", result, 4);
                        break;
                    }
                    case '6': {
                        isSuccess = updateProcess(" Year level", result, 5);
                        break;
                    }
                    case '7': {
                        isSuccess = updateProcess(" Course", result, 6);
                        break;
                    }
                    case '8': {
                        isSuccess = updateProcess(" Email", result, 7);
                        break;
                    }
                    case 'q': {
                        isSuccess = true;
                        break;
                    }
                    default: {
                        print("Invalid Choice");
                        choice = getStr("Enter your choice: ");
                    }
                }
            }
            break;
        }
        default:
            print("Invalid Choice");
    }
    if (isSuccess)
        print("updated successfully!");
    else
        print("Failed to update contact!");
    pauseProgram();
}

void viewrecord() {
    // system("cls");
    print("--------------------------------");
    print("VIEWING RECORD");
    print("--------------------------------");
    print("[1] - Roll number");
    print("[2] - Last name");
    print("--------------------------------");
    string choice = getStr("Enter your choice: ");
    switch (choice[0]) {
        case '1': {
            string RN = getStr("Enter roll number: ");
            vector<string> result = getRow(RN);
            pauseProgram();
            // system("cls");
            if (result.empty()) {
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");
                pauseProgram();
                break;
            } else {
                print("--------------------------------");
                print("Roll Number: " + result[0] + "\nLast Name: " + result[1] + "\nFirst Name: " + result[2] + "\nMiddle Name: " + result[3] + "\nContact Number: " + result[4] + "\nYear Level: " + result[5] + "\nCourse: " + result[6] + "\nEmail: " + result[7]);
                print("--------------------------------");
            }
            break;
        }
        case '2': {
            string last = getStr("Enter last name: ");
            vector<string> result = getRow(last);
            // system("cls");
            pauseProgram();
            if (result.empty()) {
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");
                pauseProgram();
            } else {
                print("--------------------------------");
                print("Roll Number: " + result[0] + "\nLast Name" + result[1] + "\nFirst Name" + result[2] + "\nMiddle Name" + result[3] + "\nContact Number" + result[4] + "\nYear Level" + result[5] + "\nCourse" + result[6] + "\nEmail" + result[7]);
                print("--------------------------------");
            }
            break;
        }
        default: {
            print("Invalid Choice");
        }
    }
    pauseProgram();
}

int startStudentRecords() {
    std::vector<int> indexes = {0, 1};
    init(studentRecordFile, csvData, indexes);
    bool exit = false;
    while (!exit) {
        // system("cls");
        print("--------------------------------");
        print("Student Record Management System");
        print("--------------------------------");
        print("[A] - Add record");
        print("[D] - Delete record");
        print("[M] - Modify record");
        print("[V] - View record");
        print("[Q] - QUIT");
        print("--------------------------------");
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
                exit = true;
                print("Exit");
                break;
            default:
                print("Invalid choice");
        }
    }
    return 0;
}
