#include <iostream>

#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;
#include "../include/systems.h"
int main() {
    bool exited = false;
    while (!exited) {
        system("cls");
        string choice = getStr("Welcome to the main menu. Please select an option:\n[B] Bank Management\n[C] Contact Management\n[R] Student Records\n[Q] Exit\n");
        switch (tolower(choice[0])) {
            case 'b': {
                system("cls");
                startBankManagement();
                break;
            }
            case 'c': {
                system("cls");
                startContactManagement();
                break;
            }
            case 'r': {
                system("cls");
                startStudentRecords();
                break;
            }
            case 'q':
                print("Thank you for using our system. Goodbye!");
                exited = true;
                break;
            default:
                print("Invalid choice. Please try again.");
        }
    }
    return 0;
}