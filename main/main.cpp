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
char userChoice(string verb = "") {
    char choice = getStr("Select an option: \n [N] " + verb + " by Name\n [E] " + verb + " by Email \n Your choice:")[0];
    return choice;
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
    string contact = name + "," + phone + "," + email + "," + address + "\n";
    bool isSuccess = appendFile("contacts.csv", contact);
    if (isSuccess) {
        print("Contact added successfully!");
        vector<string> row = {name, phone, email, address};
        csvData[name] = row;
    } else
        print("Failed to add contact!");
    pauseProgram();
}
void searchContact() {
    system("cls");
    string name = getStr("Enter name or email: ");
    vector<string> result = getRow(name);
    if (!result.empty())
        print("Name: " + result[0] + "\nPhone: " + result[1] + "\nEmail: " + result[2] + "\nAddress: " + result[3]);
    else
        print("Contact not found.");
    pauseProgram();
}
void deleteContact() {
    system("cls");
    print("Delete a contact");
    print("------------");
    string name = getStr("Enter name or email: ");
    vector<string> result = getRow(name);
    deleteRow("contacts.csv", result[0]);
    print("Contact added successfully!");
    pauseProgram();
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
            case 'n': {
                newValue = getStr("Enter new name: ");
                isSuccess = updateRow("contacts.csv", result[0], newValue, 0);
                result[0] = isSuccess ? newValue : result[0];

                break;
            }
            case 'p': {
                newValue = getStr("Enter new phone number: ");
                isSuccess = updateRow("contacts.csv", result[0], newValue, 1);
                result[1] = isSuccess ? newValue : result[1];

                break;
            }
            case 'e': {
                newValue = getStr("Enter new email: ");
                isSuccess = updateRow("contacts.csv", result[0], newValue, 2);

                break;
            }
            case 'd': {
                result[3] = getStr("Enter new address: ");
                isSuccess = updateRow("contacts.csv", result[0], newValue, 3);

                break;
            }
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

int main() {
    std::vector<int> indexes = {0, 2};
    init("contacts.csv", csvData, indexes);
    printIntro();
    bool exit = false;
    while (!exit) {
        system("cls");
        string choice = getStr("Select an option: \n[C] Add a contact\n[R] Search a contact\n[U] Update a contact\n[D] Delete a contact\n[Q]Exit\nEnter your choice: ");
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
