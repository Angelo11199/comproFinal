#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;
#include <conio.h>  // Include the <conio.h> header file

#include <iostream>
#include <vector>

using namespace std;
void printIntro() {
    print("----------------------------------------------");
    print("|| Welcome to the Contact Management System ||");
    print("----------------------------------------------");
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
int main() {
    printIntro();
    string choice = getStr("Select an option: \n1. Add a contact\n2. Search a contact\n3. Delete a contact\n4. Update a contact\n5. Exit\nEnter your choice: ");
    switch (choice[0]) {
        case '1':
            addContact();
            break;
        // case '2':
        //     searchContact();
        //     break;
        // case '3':
        //     deleteContact();
        //     break;
        // case '4':
        //     updateContact();
        //     break;
        case '5':
            exit(0);
            break;
        default:
            print("Invalid choice!");
            break;
    }
    return 0;
}
