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
    string FN = last + SEPERATOR + first + SEPERATOR + middle;
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

bool updateProcess(string noun, vector<string> result, int index) {
    string newValue = getStr("Enter new" + noun + ":");
    bool isSuccess = updateRow("record.csv", result[0], newValue, index);
    result[index] = isSuccess ? newValue : result[index];
    csvData[result[0]] = result;
    return isSuccess;
}

bool updateProcess2(string noun, vector<string> result, int index) {
    string newValue = getStr("Enter new" + noun + ":");
    bool isSuccess = updateRow("record.csv", result[1], newValue, index);
    result[index] = isSuccess ? newValue : result[index];
    csvData[result[1]] = result;
    return isSuccess;
}

void modifyrecord() {
    system("cls");
    bool isSuccess = false;
    string newValue;
    print("--------------------------------");
    print("MODIFY A RECORD");
    print("--------------------------------");
    print("[1] - Roll number");
    print("[2] - Last name");
    print("--------------------------------");
    string Choice2 = getStr("Enter your choice: ");
    switch(Choice2[0]){
        case '1':{
            string RN = getStr("Enter roll number: ");
            vector<string> result = getRow(RN);
            readFile("record.csv", result[0]);
            system("cls");
            if (result.empty()){
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");}
            else{
                system("cls");
                print("--------------------------------");
                print("PICK THE SUBJECT YOU WANT TO MODIFY");
                print("--------------------------------");
                print("[1] - Roll Number: " + result[0] + "\n[2] - Last Name: " + result[1] + "\n[3] - First Name: " + result[2] + "\n[4] - Middle Name: " + result[3] + "\n[5] - Contact Number: " + result[4] + "\n[6] - Year Level: " + result[5] + "\n[7] - Course: " + result[6] + "\n[8] - Email: " + result[7] );
                print("--------------------------------");}
                string Choice21 = getStr("Enter your choice: ");
                while(!isSuccess){
                    switch(Choice21[0]){
                        case '1':{
                            isSuccess = updateProcess("Roll number", result, 0);
                            break;
                        }
                        case '2':{
                            isSuccess = updateProcess("Last name", result, 1);
                            break;
                        }
                        case '3':{
                            isSuccess = updateProcess("First name", result, 2);
                            break;
                        }
                        case '4':{
                            isSuccess = updateProcess("Middle name", result, 3);
                            break;
                        }
                        case '5':{
                            isSuccess = updateProcess("Contact number", result, 4);
                            break;
                        }
                        case '6':{
                            isSuccess = updateProcess("Year level", result, 5);
                            break;
                        }
                        case '7':{
                            isSuccess = updateProcess("Course", result, 6);
                            break;
                        }
                        case '8':{
                            isSuccess = updateProcess("Email", result, 7);
                            break;
                        }
                    }
                }
            break;
        }
        case '2':{
            string last = getStr("Enter last name: ");
            vector<string> result = getRow(last);
            readFile("record.csv", result[1]);
            system("cls");
            if (result.empty()){
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");}
            else{
                system("cls");
                print("--------------------------------");
                print("PICK THE SUBJECT YOU WANT TO MODIFY");
                print("--------------------------------");
                print("[1] - Roll Number: " + result[0] + "\n[2] - Last Name: " + result[1] + "\n[3] - First Name: " + result[2] + "\n[4] - Middle Name: " + result[3] + "\n[5] - Contact Number: " + result[4] + "\n[6] - Year Level: " + result[5] + "\n[7] - Course: " + result[6] + "\n[8] - Email: " + result[7] );
                print("--------------------------------");}
                string Choice21 = getStr("Enter your choice: ");
                while(!isSuccess){
                    switch(Choice21[0]){
                        case '1':{
                            isSuccess = updateProcess2("Roll number", result, 0);
                            break;
                        }
                        case '2':{
                            isSuccess = updateProcess2("Last name", result, 1);
                            break;
                        }
                        case '3':{
                            isSuccess = updateProcess2("First name", result, 2);
                            break;
                        }
                        case '4':{
                            isSuccess = updateProcess2("Middle name", result, 3);
                            break;
                        }
                        case '5':{
                            isSuccess = updateProcess2("Contact number", result, 4);
                            break;
                        }
                        case '6':{
                            isSuccess = updateProcess2("Year level", result, 5);
                            break;
                        }
                        case '7':{
                            isSuccess = updateProcess2("Course", result, 6);
                            break;
                        }
                        case '8':{
                            isSuccess = updateProcess2("Email", result, 7);
                            break;
                        }
                    }
                }
            break;
        }
        default:{
            print("Invalid Choice");
        }
    }
    if (isSuccess)
        print("Contact updated successfully!");
    else
        print("Failed to update contact!");
    pauseProgram();

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
            readFile("record.csv", result[0]);
            system("cls");
            if (result.empty()){
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");}
            else{
                print("--------------------------------");
                print("Roll Number: " + result[0] + "\nLast Name: " + result[1] + "\nFirst Name: " + result[2] + "\nMiddle Name: " + result[3] + "\nContact Number: " + result[4] + "\nYear Level: " + result[5] + "\nCourse: " + result[6] + "\nEmail: " + result[7] );
                print("--------------------------------");}
            break;
        }
        case '2':{
            string last = getStr("Enter last name: ");
            vector<string> result = getRow(last);
            readFile("record.csv", result[1]);
            system("cls");
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
