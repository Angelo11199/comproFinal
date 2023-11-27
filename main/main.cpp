#include "../include/snippets.h"
using namespace std;
#include <conio.h>

#include <iomanip>
#include <iostream>
#include <vector>



void addrecord(){
    system("cls");
    string last = getStr("Enter last name: ");
    string first = getStr("Enter first name: ");
    string middle = getStr("Enter middle name: ");
    string RN = getStr("Enter roll number: ");
    while (RN.length() != 9) {
        print("Invalid roll number, try again.");
        RN = getStr("Enter roll number: ");
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
    string record = RN + SEPERATOR + FN + SEPERATOR + CN + SEPERATOR + year + SEPERATOR + course + SEPERATOR + email + "\n";
    bool isSuccess = appendFile("record.csv", record);
    if (isSuccess) {
        print("Contact added successfully!");
        vector<string> row = {RN, last, first, middle, CN, year, course, email};
        csvData[RN] = row;
        csvData[last] = row;
    } 
    else
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
            string RN = getStr("Enter roll number: ");
            vector<string> result = getRow(RN);
            deleteRow("record.csv", result[0]);
            print("Record deleted successfully!");
            break;
        }
        case '2':{
            string last = getStr("Enter last name: ");
            vector<string> result = getRow(last);
            deleteRow("record.csv", result[1]);
            print("Contact deleted successfully!");
            break;
        }
        default:{
            print("Invalid Choice");
        }
    }
    pauseProgram();
    
}

void modifyrecord() {
    system("cls");
    print("--------------------------------");
    print("MODIFY A RECORD");
    print("--------------------------------");
    string RN = getStr ("Enter roll number: ");
    vector<string> result = getRow(RN);
    //print (result[0]);
    if (result.empty()){
        print("Roll number not found.");
        pauseProgram();
    return;
    }
    deleteRow("record.csv", result[0]);
    addrecord();

} 

void viewrecord() {
    system("cls");
    print("--------------------------------");
    print("VIEWING RECORD");
    print("--------------------------------");
    print("[1] - Roll number");
    print("[2] - Last name");
    print("--------------------------------");
    string Choice3 = getStr("Enter your choice: ");
    switch(Choice3[0]){
        case '1':{
            string RN = getStr("Enter roll number: ");
            vector<string> result = getRow(RN);
            if (result.empty()){
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");}
            else{
                print("--------------------------------");
                print("Roll Number: " + result[0] + "\nLast Name" + result[1] + "\nFirst Name" + result[2] + "\nMiddle Name" + result[3] + "\nContact Number" + result[4] + "\nYear Level" + result[5] + "\nCourse" + result[6] + "\nEmail" + result[7] );
                print("--------------------------------");}
            break;
        }
        case '2':{
            string last = getStr("Enter last name: ");
            vector<string> result = getRow(last);
            if (result.empty()){
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");}
            else{
                print("--------------------------------");
                print("Roll Number: " + result[0] + "\nLast Name" + result[1] + "\nFirst Name" + result[2] + "\nMiddle Name" + result[3] + "\nContact Number" + result[4] + "\nYear Level" + result[5] + "\nCourse" + result[6] + "\nEmail" + result[7] );
                print("--------------------------------");}
            break;
        }
        default:{
            print("Invalid Choice");
        }
    }
    pauseProgram();

}

int main() {
    std::vector<int> indexes = {0, 1};
    init("record.csv", csvData, indexes);
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
        return 0;
    }
}
