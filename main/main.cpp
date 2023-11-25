#include "../include/snippets.h"  //ALWAYS ADD THIS
#include <map>
#include <string>
using namespace std;

struct Account {
    string name, address, accountType;
    double amount;
};

int main() {
    string answer;
    cout << "Welcome to Gian's & Elijah's Bank Management System!\n";
    cout << "Do you want to open an account? (yes/no): ";
    cin >> answer;
    
    if (answer == "yes") {
        Account newAccount;
        printLn("Great! Let's get started with your account creation process.");
        newAccount.name = getStr("Please enter your name: \n");
        newAccount.address = getStr("Enter your address: \n");
        newAccount.accountType = getStr("Enter your account type: \n");
        cout << "Enter amount: \n";
        cin >> newAccount.amount;
        print("Account created successfully!");

    } else if (answer == "no") {
        cout << "No problem. Let us know if you changed your mind.\n";
    } else {
        cout << "Please answer in 'yes' or 'no' only. Otherwise it will be considered as invalid.\n";
    }


    
    return 0;
}
