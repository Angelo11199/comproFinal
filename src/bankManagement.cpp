#include <map>
#include <string>

#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;
const string bankFileName = "accounts.csv";
struct Account {
    string name, address, accountType;
    double amount;
};

// Function to show account details
void showAccountDetails(vector<string> accounts) {
    print("Name: " + accounts[0]);
    print("Address: " + accounts[1]);
    print("Account Type: " + accounts[2]);
    print("Balance: $" + accounts[3]);
}

// Function to deposit funds
void deposit(vector<string> account, double amount) {
    if (amount > 0) {
        double balance = stoi(account[3]);
        balance += amount;
        print("Deposit successful. New balance: $" + to_string(balance));
        updateRow(bankFileName, account[0], to_string(balance), 3);
        csvData[account[0]][3] = to_string(balance);
    } else
        print("Invalid deposit amount. Please enter a positive amount.");
}

// Function to withdraw funds
void withdraw(vector<string> acc, double amount) {
    double balance = stoi(acc[3]);
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        print("Withdrawal successful. New balance: $" + to_string(balance));
        updateRow(bankFileName, acc[0], to_string(balance), 3);
        csvData[acc[0]][3] = to_string(balance);
    } else {
        print("Invalid withdrawal amount or insufficient funds.");
    }
}
void searchAccount(string name) {
    vector<string> account = getRow(name);
    if (account.size() == 0)
        print("Account not found.");
    else {
        print("Account found!");
        print("Name: " + account[0]);
        print("Address: " + account[1]);
        print("Account Type: " + account[2]);
        print("Balance: $" + account[3]);
    }
}
string createAccount() {
    Account newAccount;
    bool isSuccess;
    print("Great! Let's get started with your account creation process.");
    newAccount.name = getStr("Please enter your name: \n");
    newAccount.address = getStr("Enter your address: \n");
    newAccount.accountType = getStr("Enter your account type: \n");
    newAccount.amount = getNum("Enter amount: \n");
    string content = newAccount.name + SEPERATOR + newAccount.address + SEPERATOR + newAccount.accountType + SEPERATOR + to_string(newAccount.amount);
    isSuccess = appendFile(bankFileName, content + "\n");
    if (isSuccess) {
        csvData[newAccount.name] = {newAccount.name, newAccount.address, newAccount.accountType, to_string(newAccount.amount)};
        print("Account created successfully!");
        return "";
    }
    return newAccount.name;
}
int startBankManagement() {
    vector<int> indexes = {0};
    init(bankFileName, csvData, indexes);
    string answer;
    bool exited = false;
    vector<string> account;
    print("--------------------------------------------------------");
    print("||Welcome to Gian's & Elijah's Bank Management System!||");
    print("--------------------------------------------------------");
    answer = getStr("Would you like to create an account? (yes/no)");
    if (answer == "no") {
        print("No problem. Let us know if you changed your mind.");
        while (!exited) {
            print("Choose an option:");
            print("1. Create an account");
            print("4. Search for an account");
            print("5. Exit");
            int choice = getNum("Enter your choice: ");
            switch (choice) {
                case 1:
                    account = csvData[createAccount()];
                    exited = account.size() > 0;
                    break;
                case 4: {
                    string searchName = getStr("Enter the name to search for: ");
                    searchAccount(searchName);
                    break;
                }
                case 5: {
                    print("Exiting the program. Thank you!");
                    exited = true;
                    break;
                }
                default: {
                    print("Invalid choice. Please try again.");
                }
            }
        }
    } else {
        createAccount();
        exited = false;
    }
    while (!exited) {
        print("Choose an option:");
        print("1. Show account details");
        print("2. Deposit");
        print("3. Withdraw");
        print("4. Search for an account");
        print("5. Exit");
        int choice = getNum("Enter your choice: ");
        switch (choice) {
            case 1:
                showAccountDetails(account);
                break;
            case 2: {
                double depositAmount = getNum("Enter the deposit amount: $");
                deposit(account, depositAmount);
                break;
            }
            case 3: {
                double withdrawAmount = getNum("Enter the withdrawal amount: $");
                withdraw(account, withdrawAmount);
                break;
            }
            case 4: {
                string searchName = getStr("Enter the name to search for: ");
                vector<string> account = getRow(searchName);
                if (account.size() == 0)
                    print("Account not found.");
                else
                    showAccountDetails(account);
                break;
            }
            case 5: {
                print("Exiting the program. Thank you!");
                exited = true;
                break;
            }
            default:
                printLn("Invalid choice. Please try again.");
        }
    }

    return 0;
}
