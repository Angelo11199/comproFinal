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
void getAccount() {
    string accountNumber = getStr("Please enter your account number:");
    vector<string> accountInfo = getRow(accountNumber);
    if (accountInfo.size() == 0) {
        print("Account not found");
        return;
    }
    int pin = getPin();
    if (accountInfo[7] == to_string(pin)) {
        print("Account found");
        // print account info
        for (auto info : accountInfo) {
            print(info);
        }
        return;
    }
    string pin = getStr("Please enter your pin:");
}
string loopTillNotNull(string prompt = "") {
    string userInput = getStr(prompt);
    do {
        userInput = getStr(prompt);
        if (userInput == "") {
            print("Invalid input. Try again at the beginning.");
            return;
        }
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
        char digit = getch();
        printLn("*");
        if (isdigit(digit)) {
            pinLength += digit;
        } else {
            print("Invalid input. Try again at the beginning.");
            pinLength = "";
            continue;
        }
        if (pinLength.length() == PINDIGITS) {
            print("");
            print("Pin entered successfully");
            cin.ignore();
            return stoi(pinLength);
        }
    } while (pinLength.length() != PINDIGITS);
    return 0;
}
bool createAccount() {
    BankInfo bankInfo;
    bankInfo.name = loopTillNotNull("Please enter your name:");
    bankInfo.address = loopTillNotNull("Please enter your address:");
    bankInfo.phone = loopTillNotNull("Please enter your phone number:");
    do bankInfo.email = loopTillNotNull("Please enter your email:");
    while (bankInfo.email.find("@") == string::npos);
    do {
        bankInfo.accountType = loopTillNotNull("Please enter your account type:");
        if (bankInfo.accountType != "Checking" && bankInfo.accountType != "Savings")
            print("Invalid input. Try again at the beginning.");
    } while (bankInfo.accountType != "Checking" && bankInfo.accountType != "Savings");

    bankInfo.balance = loopTillNotNull("Please enter your balance:");
    string firstPin, secondPin;
    do {
        print("Please set your pin:");
        firstPin = getPin();
        print("");
        print("enter your pin again:");
        secondPin = getPin();
        if (firstPin != secondPin) {
            print("Pin does not match. Try again");
        }
        bankInfo.pin = stoi(firstPin);
    } while (firstPin != secondPin);
    bankInfo.accountNumber = to_string(rand() % 1000000);
    if (getRow(bankInfo.accountNumber).size() != 0) {
        bankInfo.accountNumber = to_string(rand() % 1000000);
    }
    string accountInfo = bankInfo.name + SEPERATOR + bankInfo.address + SEPERATOR + bankInfo.phone + SEPERATOR + bankInfo.email + SEPERATOR + bankInfo.accountNumber + SEPERATOR + bankInfo.accountType + SEPERATOR + bankInfo.balance + SEPERATOR + to_string(bankInfo.pin);
    appendFile("bankInfo.csv", accountInfo);
    return true;
}
int main() {
    printIntro("========================================");
    printIntro("||Welcome to the Bank Management System||");
    printIntro("========================================");
    pauseProgram();
    vector<int> indexes = {0, 4};
    init("bankInfo.csv", csvData, indexes);
    // create an input that doesn't show what is being typed
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
        print("Q. Quit");
        string choice = getStr("Your choice:");
        switch (tolower(choice[0])) {
            case 'c':
                createAccount();
                break;
            case 'r':
                break;
            case 'u':
                break;
            case 'd':
                break;
            case 'q':
                exit = true;
                break;
            default:
                print("Invalid choice!");
                break;
        };
    }
    print("Good bye");
    return 0;
}
