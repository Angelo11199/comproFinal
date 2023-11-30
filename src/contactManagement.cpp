#include "../include/snippets.h"
using namespace std;
#include <conio.h>

#include <iostream>
#include <vector>
void printIntro() {
    print("----------------------------------------------");
    print("|| Welcome to the Contact Management System ||");
    print("----------------------------------------------");
    pauseProgram();
}
void addContact() {
    system("cls");
    print("Add a contact");
    print("------------");
    string name = getStr("Enter name: ");
    string phone = getStr("Enter phone number: ");
    while (phone.length() != 11) {
        print("Invalid phone number!");
        phone = getStr("Enter phone number: ");
    }
    string email = getStr("Enter email: ");
    while (email.find("@") == string::npos) {
        print("Invalid email!");
        email = getStr("Enter email: ");
    }
    string address = getStr("Enter current address: ");
    string contact = name + SEPERATOR + phone + SEPERATOR + email + SEPERATOR + address + "\n";
    bool isSuccess = appendFile("contacts.csv", contact);
    if (isSuccess) {
        print("Contact added successfully!");
        vector<string> row = {name, phone, email, address};
        csvData[name] = row;
        csvData[email] = row;
    } else
        print("Failed to add contact!");
    pauseProgram();
}
void searchContact() {
    system("cls");
    string name = getStr("Enter name or email: ");
    vector<string> result = getRow(name);
    if (result.empty())
        print("Contact not found.");
    else
        print("Name: " + result[0] + "\nPhone: " + result[1] + "\nEmail: " + result[2] + "\nAddress: " + result[3]);
    pauseProgram();
}
void deleteContact() {
    system("cls");
    print("Delete a contact");
    print("------------");
    string name = getStr("Enter name or email: ");
    vector<string> result = getRow(name);
    deleteRow("contacts.csv", result[0]);
    print("Contact deleted successfully!");
    pauseProgram();
}
bool updateProcess(string noun, vector<string> result, int index) {
    string newValue = getStr("Enter new" + noun + ":");
    bool isSuccess = updateRow("contacts.csv", result[0], newValue, index);
    result[index] = isSuccess ? newValue : result[index];
    csvData[result[0]] = result;
    return isSuccess;
}
void updateContact() {
    system("cls");
    bool isSuccess = false;
    string newValue;
    print("Update a contact");
    print("------------");
    string name = getStr("Enter the name you wish to update: ");
    vector<string> result = getRow(name);
    if (result.empty()) {
        print("Contact not found.");
        pauseProgram();
        return;
    }
    char choice = getStr("Select to update: \n [N] Update name\n [P] Update phone number\n [E] Update email\n [A] Update address\n [B] Go back \nYour choice:")[0];
    while (!isSuccess) {
        switch (tolower(choice)) {
            case 'n':
                isSuccess = updateProcess("name", result, 0);
                break;
            case 'p':
                isSuccess = updateProcess("phone number", result, 1);
                break;
            case 'e':
                isSuccess = updateProcess("email", result, 2);
                break;
            case 'd':
                isSuccess = updateProcess("address", result, 3);
                break;
            case 'b':
                isSuccess = true;
                break;
            default:
                print("Invalid choice!");
                break;
        }
    }
    if (isSuccess)
        print("Contact updated successfully!");
    else
        print("Failed to update contact!");
    pauseProgram();
}

int startContactManagement() {
    vector<int> indexes = {0, 2};
    init("contacts.csv", csvData, indexes);
    printIntro();
    bool exit = false;
    while (!exit) {
        system("cls");
        string choice = getStr("Select an option: \n[C] Add a contact\n[R] Search a contact\n[U] Update a contact\n[D] Delete a contact\n[Q] Exit\nEnter your choice: ");
        switch (tolower(choice[0])) {
            case 'c':
                addContact();
                break;
            case 'r':
                searchContact();
                break;
            case 'u':
                updateContact();
                break;
            case 'd':
                deleteContact();
                break;
            case 'q':
                exit = true;
                break;
            default:
                print("Invalid choice!");
                break;
        }
    }
    print("Good bye");
    return 0;
}
