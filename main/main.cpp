#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;
#include <conio.h>  // Include the <conio.h> header file

#include <iostream>
#include <vector>

using namespace std;
#include <cstdlib>  // Include the <cstdlib> header file for system("cls")

void printIntro() {
    print("----------------------------------------------");
    print("|| Welcome to the Contact Management System ||");
    print("----------------------------------------------");
    print("Press any key to continue...");
    getch();  // Wait for user input
    // system("cls"); //add this once complete
}

void addContact() {
    print("Add a contact");
    print("------------");
    string name = getStr("Enter name: ");
    string phone = getStr("Enter phone number: ");
    string email = getStr("Enter email: ");
    string address = getStr("Enter current address: ");
    string contact = name + "," + phone + "," + email + "," + address + "\n";
    appendFile("contacts.csv", contact);
    print("Contact added successfully!");
}
void searchContact() {
    string content;
    bool readSuccess = readFile("contacts.csv", content);
    if (!readSuccess) {
        print("Error reading file!");
        // todo: create a file instead
        return;
    }
    vector<string> contacts;
    string contact;
    splitData(content, "\n", contacts);
    // print contacts
    for (int i = 0; i < contacts.size() - 1; i++) {
        vector<string> contactDetails;
        splitData(contacts[i], ",", contactDetails);
        print("Name: " + contactDetails[0]);
        print("Phone: " + contactDetails[1]);
        print("Email: " + contactDetails[2]);
        print("Address: " + contactDetails[3]);
        print("----------------------------");
    }
    print("Search a contact");
    print("------------");
    string name = getStr("Enter name: ");
    print("Contact added successfully!");
}
int main() {
    printIntro();
    bool exit = false;
    while (!exit) {
        string choice = getStr("Select an option: \n[C] Add a contact\n[R]Search a contact\n[U] Update a contact\n[D] Delete a contact\n[Q]Exit\nEnter your choice: ");
        switch (tolower(choice[0])) {
            case 'c':
                addContact();
                break;
            case 'r':
                searchContact();
                break;
            // case '3':
            //     deleteContact();
            //     break;
            // case '4':
            //     updateContact();
            //     break;
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
