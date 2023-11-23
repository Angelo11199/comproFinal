#include "../include/snippets.h"  //ALWAYS ADD THIS
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
    char choice = getStr("Select an option: \n [N] " + verb + " by Name\n [E] " + verb + " by Email")[0];
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
    appendFile("contacts.csv", contact);
    print("Contact added successfully!");
}
void searchContact() {
    char choice = userChoice("Search");
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
    print("Search a contact");
    print("------------");
    char searchBy = tolower(userChoice("Update"));
    switch (searchBy) {
        case 'n': {
            string name = getStr("Enter name: ");
            for (int i = 0; i < contacts.size(); i++) {
                splitData(contacts[i], ",", contact);
                if (contact[0] == name) {
                    printLn("Name: " + contact[0] + "\nPhone: " + contact[1] + "\nEmail: " + contact[2] + "\nAddress: " + contact[3]);
                    break;
                }
            }
            break;
        }
        case 'e': {
            string email = getStr("Enter email: ");
            for (int i = 0; i < contacts.size(); i++) {
                splitData(contacts[i], ",", contact);
                if (contact[2] == email) {
                    printLn("Name: " + contact[0] + "\nPhone: " + contact[1] + "\nEmail: " + contact[2] + "\nAddress: " + contact[3]);
                    break;
                }
            }
            break;
        }
    }
    string name = getStr("Enter name: ");
    print("Contact added successfully!");
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
