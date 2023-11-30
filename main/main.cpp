#include <iostream>

#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;
#include "../include/systems.h"
int main() {
    while (true) {
        string choice = getStr("Welcome to the main menu. Please select an option:\n[B] Bank Management\n[C] Contact Management\n[R] Student Records\n[Q] Exit\n");
        switch (tolower(choice[0])) {
            case 'B': {
                system("cls");
                startBankManagement();
                break;
            }
            case 'C': {
                system("cls");
                startContactManagement();
                break;
            }
            case 'R': {
                system("cls");
                startStudentRecords();
                break;
            }
            case 'Q':
                print("Thank you for using our system. Goodbye!");
                exit(0);
            default:
                print("Invalid choice. Please try again.");
        }
    }
    return 0;
}