#include <map>
#include <string>

#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;

struct Account {
    string name, address, accountType;
    double amount;
};

int main() {
    string answer;
    print("Welcome to Gian's & Elijah's Bank Management System!");
    answer = getStr("Would you like to create an account? (yes/no)");
    if (answer == "no") {
        print("No problem. Let us know if you changed your mind.");
        return 0;
    }
    Account newAccount;
    print("Great! Let's get started with your account creation process.");
    newAccount.name = getStr("Please enter your name: \n");
    newAccount.address = getStr("Enter your address: \n");
    newAccount.accountType = getStr("Enter your account type: \n");
    newAccount.amount = getNum("Enter amount: \n");
    print("Account created successfully!");
}
