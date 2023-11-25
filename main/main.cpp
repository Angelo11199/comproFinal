#include "../include/snippets.h"
using namespace std;
#include <conio.h>  // Include the <conio.h> header file

#include <iostream>
#include <vector>
using namespace std;
// all functions should be on a different file.
void printIntro() {
    print("----------------------------------------------");
    print("|| Welcome to the Contact Management System ||");
    print("----------------------------------------------");
    print("Press any key to continue...");
    getch();  // Wait for user input
    // system("cls"); //add this once complete
}
char userChoice(string verb = "") {
    char choice = getStr("Select an option: \n [N] " + verb + " by Name\n [E] " + verb + " by Email \n Your choice:")[0];

    return choice;
}
void addContact() {
    print("Add a contact");
    print("------------");
    string name = getStr("Enter name: ");
    string phone = getStr("Enter phone number: ");
    string email = getStr("Enter email: ");
    string address = getStr("Enter current address: ");
    string contact = name + "," + phone + "," + email + "," + address + "\n";
    bool isSuccess = appendFile("contacts.csv", contact);
    if (isSuccess) {
        print("Contact added successfully!");
        return;
    }
    print("Failed to add contact!");
}
void searchContact() {
    string name = getStr("Enter name or email: ");
    vector<string> result = getRow(name);
    if (!result.empty()) {
        print("Name: " + result[0] + "\nPhone: " + result[1] + "\nEmail: " + result[2] + "\nAddress: " + result[3]);
        return;
    } else
        print("Contact not found.");
}
void deleteContact() {
    char choice = userChoice("Delete");
    print("Delete a contact");
    print("------------");
    string name = getStr("Enter name: ");
    print("Contact added successfully!");
}
void updateContact() {
    print("Update a contact");
    print("------------");
    string name = getStr("Enter name: ");
    print("Contact added successfully!");
}

int main() {
    std::vector<int> indexes = {0, 2};
    init("contacts.csv", csvData, indexes);
    printIntro();
    bool exit = false;
    while (!exit) {
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
