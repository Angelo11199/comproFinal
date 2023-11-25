#include <map>

#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;
struct Account {
    string name, address, accountType;
    double amount;
};
/*
    How to use Struct:
        Account a;
        a.name = "Gian";
        a.address = "Bacoor";
        a.accountType = "Savings";
        a.amount = 1000;

*/
int main() {
    cout << "Welcome to Gian's & Elijah's Bank Management System!\n";
    string answer = getStr("Do you want to open an account? (yes/no):");
    if (answer == "yes") {
        cout << "Kindly enter your";
    }
    print("");
    return 0;
}