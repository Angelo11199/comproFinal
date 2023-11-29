#include "../include/snippets.h"
using namespace std;
#include <conio.h>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#define PINDIGITS 6
// craeting the structure for the bank info
struct BankInfo {
    string name;
    string address;
    string phone;
    string email;
    string accountNumber;
    string accountType;
    string balance;
    int pin;
};
void printInfo(vector<string> bankInfo) {
    string info = "";
    print("Name: " + bankInfo[0]);
    print("Address: " + bankInfo[1]);
    print("Phone: " + bankInfo[2]);
    print("Email: " + bankInfo[3]);
    print("Account Number: " + bankInfo[4]);
    print("Account Type: " + bankInfo[5]);
    print("Balance: " + bankInfo[6]);
    print(info);
}
const string fileName = "bankInfo.csv";
string loopTillNotNull(string prompt = "") {
    string userInput;
    do {
        userInput = getStr(prompt);
        if (userInput == "")
            print("Invalid input. Try again.");
    } while (userInput == "");

    return userInput;
}
int getHour() {
    auto currentTime = std::chrono::system_clock::now();
    std::time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    std::tm* currentTime_tm = std::localtime(&currentTime_t);
    int hours = currentTime_tm->tm_hour;
    return hours;
}
void printIntro(string s) {
    for (const auto c : s) {
        cout << c << flush;
        this_thread::sleep_for(10ms);
    }
    print("");
}
int getPin() {
    string pinLength = "";
    char* p;
    do {
        if (pinLength.length() == PINDIGITS) {
            print("");
            print("Pin entered successfully");
            break;
        }
        char digit = getch();
        printLn("*");
        if (isdigit(digit))
            pinLength += digit;
        else {
            print("Invalid input. Try again at the beginning.");
            pinLength = "";
            continue;
        }
    } while (pinLength.length() != PINDIGITS);
    return stoi(pinLength);
}
bool checkPin(int correctPin) {
    int pin = getPin();
    if (pin == correctPin) return true;
    return false;
}
void createAccount() {
    BankInfo bankInfo;
    bankInfo.name = loopTillNotNull("Please enter your name:");
    bankInfo.address = loopTillNotNull("Please enter your address:");
    bankInfo.phone = getStr("Please enter your phone number:");
    while (bankInfo.phone.length() != 11) {
        print("Invalid phone number. Try again");
        bankInfo.phone = getStr("Please enter your phone number:");
    }
    do bankInfo.email = loopTillNotNull("Please enter your email:");
    while (bankInfo.email.find("@") == string::npos);
    do {
        bankInfo.accountType = loopTillNotNull("Please enter your account type:");
        for (auto& c : bankInfo.accountType) c = tolower(c);
        if (bankInfo.accountType != "checking" && bankInfo.accountType != "savings")
            print("Invalid input. Try again.");
    } while (bankInfo.accountType != "checking" && bankInfo.accountType != "savings");
    bankInfo.balance = to_string(getNum("Please enter your initial deposit:"));
    int firstPin;
    bool isCorrect;
    do {
        print("Please set your pin:");
        firstPin = getPin();
        print("");
        print("enter your pin again:");
        isCorrect = checkPin(firstPin);
        print("");
        if (!isCorrect) {
            print("Pin does not match. Try again");
            continue;
        }
        bankInfo.pin = firstPin;
    } while (!isCorrect);
    // generate a unique random account number
    while (true) {
        bankInfo.accountNumber = to_string(rand() % 1000000);
        if (getRow(bankInfo.accountNumber).size() == 0) break;
    }
    string accountInfo = bankInfo.name + SEPERATOR + bankInfo.address + SEPERATOR + bankInfo.phone + SEPERATOR + bankInfo.email + SEPERATOR + bankInfo.accountNumber + SEPERATOR + bankInfo.accountType + SEPERATOR + bankInfo.balance + SEPERATOR + to_string(bankInfo.pin) + "\n";
    bool isSuccess = appendFile(fileName, accountInfo);
    if (!isSuccess)
        print("Account creation failed");
    else
        print("Account creation successful");
    csvData[bankInfo.accountNumber] = {bankInfo.name, bankInfo.address, bankInfo.phone, bankInfo.email, bankInfo.accountNumber, bankInfo.accountType, bankInfo.balance, to_string(bankInfo.pin)};
    printInfo(csvData[bankInfo.accountNumber]);
    pauseProgram();
}
void readAccount() {
    string accountNumber = getStr("Please enter your account number:");
    vector<string> accountInfo = getRow(accountNumber);
    print(accountInfo.size());
    if (accountInfo.size() == 0) {
        print("Account not found");
        pauseProgram();
        return;
    }
    print("Please enter your pin for verification");
    bool isCorrect = checkPin(stoi(accountInfo[7]));
    print("");
    if (isCorrect) {
        print("Account found");
        printInfo(accountInfo);
        pauseProgram();
        return;
    }
}
void updateAccount() {
    string choice;
    string accountNumber = getStr("Please enter your account number:");
    BankInfo bankInfo;
    vector<string> accountInfo = getRow(accountNumber);
    if (accountInfo.size() == 0) {
        print("Account not found");
        pauseProgram();
        return;
    }
    print("Please enter your pin for verification");
    bool isCorrect = checkPin(stoi(accountInfo[7]));
    print("");

    if (!isCorrect) {
        int tries = 0;
        while (tries < 3) {
            print("Invalid pin. Try again");
            isCorrect = checkPin(stoi(accountInfo[7]));
            if (isCorrect) break;
            tries++;
        }
        if (tries == 3) {
            print("Too many tries. Try again later");
            pauseProgram();
        }
        return;
    }
    print("Account found");
    print("What would you like to update?");
    print("[P] Pin");
    print("[E] Email");
    print("[N] Name");
    print("[T] Phone");
    print("[A] Address");
    choice = getStr("Your choice:");
    while (true) {
        if (choice.length() == 0) updateAccount();
        print("Invalid choice. Try again");
        choice = tolower(getStr("Your choice:")[0]);
        if (choice[0] == 'p' || choice[0] == 'e' || choice[0] == 'n' || choice[0] == 't' || choice[0] == 'a') break;
        print(choice);
    }
    switch (choice[0]) {
        case 'p': {
            int firstPin, secondPin;
            do {
                print("Please set your new pin:");
                firstPin = getPin();
                print("");
                print("enter your pin again:");
                secondPin = getPin();
                if (firstPin != secondPin) {
                    print("Pin does not match. Try again");
                    continue;
                }
                accountInfo[6] = firstPin;
                updateRow(fileName, accountInfo[0], to_string(firstPin), 6);
                csvData[accountInfo[0]] = accountInfo;
            } while (firstPin != secondPin);
            break;
        }

        case 'e': {
            do {
                bankInfo.email = loopTillNotNull("Please enter your new email:");
                if (bankInfo.email.find("@") == string::npos) print("Invalid input. Try again.");
            } while (bankInfo.email.find("@") == string::npos);
            updateRow(fileName, accountInfo[0], bankInfo.email, 3);
            accountInfo[3] = bankInfo.email;
            csvData[accountInfo[0]] = accountInfo;
        }
        case 'n': {
            bankInfo.name = loopTillNotNull("Please enter your new name:");
            updateRow(fileName, accountInfo[0], bankInfo.name, 0);
            accountInfo[0] = bankInfo.name;
            csvData[accountInfo[0]] = accountInfo;
        } break;
            break;
        case 't':
            bankInfo.phone = loopTillNotNull("Please enter your new phone number:");
            updateRow(fileName, accountInfo[0], bankInfo.phone, 2);
            accountInfo[2] = bankInfo.phone;
            csvData[accountInfo[0]] = accountInfo;
            break;
        case 'a':
            bankInfo.address = loopTillNotNull("Please enter your new address:");
            updateRow(fileName, accountInfo[0], bankInfo.address, 1);
            accountInfo[1] = bankInfo.address;
            csvData[accountInfo[0]] = accountInfo;
            break;
        default:
            print("Invalid choice!");
            break;
    };
    pauseProgram();
}
bool deleteAccount() {
    string accountNumber = getStr("Please enter your account number:");
    vector<string> accountInfo = getRow(accountNumber);
    if (accountInfo.size() == 0) {
        print("Account not found");
        pauseProgram();
        return false;
    }
    print("Please enter your pin for verification");
    int pin = getPin();
    print("");
    if (accountInfo[7] != to_string(pin)) return false;
    print("Account found");
    printInfo(accountInfo);
    print("Are you sure you want to delete this account?");
    print("Y. Yes");
    print("N. No");
    char choice = tolower(getStr("Your choice:")[0]);
    while (choice != 'y' || choice != 'n') choice = tolower(getStr("Your choice:")[0]);
    if (choice == 'n') return false;
    deleteRow(fileName, accountNumber);
    csvData.erase(accountInfo[0]);
    csvData.erase(accountInfo[4]);
    pauseProgram();
    return true;
}

int main() {
    printIntro("========================================");
    printIntro("||Welcome to the Bank Management System||");
    printIntro("========================================");
    pauseProgram();
    vector<int> indexes = {4};
    init(fileName, csvData, indexes);
    bool exit = false;
    while (!exit) {
        system("cls");
        int hours = getHour();
        if (hours >= 0 && hours < 12)
            printLn("Good Morning!");
        else if (hours >= 12 && hours < 18)
            printLn("Good Afternoon!");
        else if (hours >= 18 && hours <= 23)
            printLn("Good Evening!");
        printLn(" Welcome to the Bank Management System");
        print("");
        print("Please select an option");
        print("C. Create a new account");
        print("R. Get an existing account");
        print("U. Update an existing account");
        print("D. Delete an existing account");
        print("W - Withdraw");
        print("E - Deposit");
        print("Q. Quit");
        string choice = getStr("Your choice:");
        switch (tolower(choice[0])) {
            case 'c':
                createAccount();
                break;
            case 'r':
                readAccount();
                break;
            case 'u':
                updateAccount();
                break;
            case 'd':
                deleteAccount();
                break;
            case 'w': {
                string accountNumber = getStr("Please enter your account number:");
                vector<string> accountInfo = getRow(accountNumber);
                if (accountInfo.size() == 0) {
                    print("Account not found");
                    pauseProgram();
                    return false;
                }
                print("Please enter your pin for verification");
                int pin = getPin();
                if (accountInfo[7] != to_string(pin)) {
                    int tries = 0;
                    while (tries < 3) {
                        print("Invalid pin. Try again");
                        pin = getPin();
                        if (accountInfo[7] == to_string(pin)) break;
                        tries++;
                    }
                    if (tries == 3) print("Too many tries. Try again later");
                    return false;
                }
                int withdraw = getNum("Please enter withdraw amount:");
                if (stoi(accountInfo[6]) < withdraw) {
                    print("Insufficient funds");
                    break;
                }
                updateRow(fileName, accountInfo[0], to_string(stoi(accountInfo[6]) - withdraw), 6);
                accountInfo[6] = to_string(stoi(accountInfo[6]) - withdraw);
                csvData[accountInfo[0]] = accountInfo;
                pauseProgram();
                print("Withdraw successful");
                break;
            }
            case 'e': {
                string accountNumber = getStr("Please enter your account number:");
                vector<string> accountInfo = getRow(accountNumber);
                if (accountInfo.size() == 0) {
                    print("Account not found");
                    pauseProgram();
                    break;
                }
                print("Please enter your pin for verification");
                int pin = getPin();
                if (accountInfo[7] != to_string(pin)) {
                    int tries = 0;
                    while (tries < 3) {
                        print("Invalid pin. Try again");
                        pin = getPin();
                        if (accountInfo[7] == to_string(pin)) break;
                        tries++;
                    }
                    if (tries == 3) print("Too many tries. Try again later");
                    return false;
                }
                int deposit = getNum("Please enter deposit amount:");
                updateRow(fileName, accountInfo[0], to_string(stoi(accountInfo[6]) + deposit), 6);
                accountInfo[6] = to_string(stoi(accountInfo[6]) + deposit);
                csvData[accountInfo[0]] = accountInfo;
                print("Deposit successful");
                pauseProgram();
                break;
            }
            case 'q':
                exit = true;
                break;
            default:
                print("Invalid choice!");
                break;
        };
    };
    print("Good bye");
    return 0;
}
