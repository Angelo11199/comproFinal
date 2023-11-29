#include <map>
#include <string>

#include "../include/snippets.h" //ALWAYS ADD THIS
using namespace std;

struct Account {
    string name, address, accountType;
    double amount;
};

// Function to show account details
void showAccountDetails(const Account& acc) {
    print("Name: " + acc.name);
    print("Address: " + acc.address);
    print("Account Type: " + acc.accountType);
    print("Balance: $" + to_string(acc.amount));
}

// Function to deposit funds
void deposit(Account& acc, double amount) {
    if (amount > 0) {
        acc.amount += amount;
        print("Deposit successful. New balance: $" + to_string(acc.amount));
    } else {
        print("Invalid deposit amount. Please enter a positive amount.");
    }
}

// Function to withdraw funds
void withdraw(Account& acc, double amount) {
    if (amount > 0 && amount <= acc.amount) {
        acc.amount -= amount;
        print("Withdrawal successful. New balance: $" + to_string(acc.amount));
    } else {
        print("Invalid withdrawal amount or insufficient funds.");
    }
}

// Function to search for an account by name
void searchContact(const map<string, Account>& accounts, const string& accountName) {
    auto it = accounts.find(accountName);
    if (it != accounts.end()) {
        Account selectedAccount = it->second;
        showAccountDetails(selectedAccount);
    } else {
        printLn("Account not found.");
    }
}

int main() {
    map<string, Account> accounts;
    string answer;
    print("-------------------------------------------------------");
    print("Welcome to Gian's & Elijah's Bank Management System!");
    print("-------------------------------------------------------");
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
    accounts[newAccount.name] = newAccount;
    print("Account created successfully!");

    while (true) {
        print("\nChoose an option:");
        print("1. Show account details");
        print("2. Deposit");
        print("3. Withdraw");
        print("4. Search for an account");
        print("5. Exit");

        int choice = getNum("Enter your choice: ");

        if (choice == 5) {
            print("Exiting the program. Thank you!");
            break;
        }

        if (choice == 4) {
            string searchName = getStr("Enter the name to search for: ");
            searchContact(accounts, searchName);
            continue;
        }

        string accountName;
        print("Enter account name: ");
        getline(cin, accountName);

        auto it = accounts.find(accountName);
        if (it != accounts.end()) {
            Account& selectedAccount = it->second;

            switch (choice) {
                case 1:
                    showAccountDetails(selectedAccount);
                    break;
                case 2: {
                    double depositAmount = getNum("Enter the deposit amount: $");
                    deposit(selectedAccount, depositAmount);
                    break;
                }
                case 3: {
                    double withdrawAmount = getNum("Enter the withdrawal amount: $");
                    withdraw(selectedAccount, withdrawAmount);
                    break;
                }
                default:
                    printLn("Invalid choice. Please try again.");
            }
        } else {
            printLn("Account not found.");
        }
    }

    return 0;
}
