#include "../include/snippets.h"
//to connect the code to the snippet.h so it can use the functions made
using namespace std;
#include <conio.h>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

//Declare the start() so it can be later(line 216) use for going back to the main menu of the program   
void start();

//Menu for deleting a data in the database
void removestock() {
    system("cls");
    print("---------------------------------");
    print("REMOVING STOCK");
    print("---------------------------------");
    string barcode = getStr("Enter Barcode: ");
    vector<string> result = getRow(barcode);
    deleteRow("inventory.csv", result[0]);
    print("Record deleted successfully!");
    pauseProgram();
    start();
}

//Menu for viewing and search specific data or to view all data in the database
void viewstock() {
    system("cls");
    print("-----------------------------------");
    print("VIEWING INVENTORY");
    print("-----------------------------------");
    print("[1] - View Specific Product");
    print("[2] - View All");
    print("[3] - Go Back");
    print("-----------------------------------");
    string choice2 = getStr("Enter your choice: ");
    switch (choice2[0]) {
        case '1': {
            string barcode = getStr("Enter Bar Code: ");
            vector<string> result = getRow(barcode);
            pauseProgram();
            system("cls");
            if (result.empty()) {
                print("--------------------------------");
                print("Product not found.");
                print("--------------------------------");
                pauseProgram();
                viewstock();
                break;
            } else {
                print("--------------------------------");
                print("Bar Code: " + result[0] + "\nProduct Name: " + result[1] + "\nType: " + result[2] + "\nNumber of Stocks: " + result[3]);
                print("--------------------------------");
                pauseProgram();
                start();
            }
            break;
        }
        case '2':{
            system("cls");
            print("--------------------------------");
            string contents;
            readFile("inventory.csv", contents);
            print(contents);
            print("--------------------------------");
            pauseProgram();
            break;
        }
        case '3': {
            start();
            break;
        }
        default: {
            print("Invalid Choice");
            pauseProgram();
            viewstock();
            break;
        }
    }
}

//This code and process to modifying an data in the database
bool updateProcess(string noun, vector<string> result, int index) {
    string newValue = getStr("Enter New " + noun + ": ");
    bool isSuccess = updateRow("inventory.csv", result[0], newValue, index);
    result[index] = isSuccess ? newValue : result[index];
    csvData[result[0]] = result;

    return isSuccess;
}

//Menu that will modify and edit a specific data inside the database
void updatestock() {
    system("cls");
    bool isSuccess = false;
    string newValue;
    print("---------------------------------");
    print("UPDATING STOCK");
    print("---------------------------------");
    string barcode = getStr("Enter the Bar Code: ");
    vector<string> result = getRow(barcode);
    system("cls");
    if (result.empty()) {
        print("--------------------------------");
        print("Record not found.");
        print("--------------------------------");
        start();
        pauseProgram();
    } else {
        system("cls");
        print("--------------------------------");
        print("PICK THE SUBJECT YOU WANT TO MODIFY");
        print("--------------------------------");
        print("[1] - Bar Code: " + result[0] + "\n[2] - Product Name: " + result[1] + "\n[3] - Type: " + result[2] + "\n[4] - Stocks: " + result[3] + "\n[Q] - Quit to Start");
        print("--------------------------------");
    }
    string choice = getStr("Enter your choice: ");
    while (!isSuccess) {
        switch (tolower(choice[0])) {
            case '1': {
                isSuccess = updateProcess("Bar Code", result, 0);
                break;
            }
            case '2': {
                isSuccess = updateProcess("Product Name", result, 1);
                break;
            }
            case '3': {
                isSuccess = updateProcess("Type", result, 2);
                break;
            }
            case '4': {
                isSuccess = updateProcess("Number of Stocks", result, 3);
                break;
            }
            case 'q': {
                isSuccess = true;
                start();
                break;
            }
            default: {
                print("Invalid Choice");
                updatestock();
            }
        }
    }
    if (isSuccess) {
        print("--------------------------------");
        print("Updated Successfully!");
        print("--------------------------------");
    } else {
        print("--------------------------------");
        print("Failed to update inventory!");
        print("--------------------------------");
    }
    start();
    pauseProgram();
}

//Menu that will add new data in the database
void addstock() {
    system("cls");
    print("---------------------------------");
    print("ADDING NEW STOCK");
    print("---------------------------------");
    string barcode = getStr("Enter Bar Code(4-digit): ");
    while (barcode.length() != 4) {
        print("Invalid Bar Code, try again.");
        barcode = getStr("Enter Bar Code: ");
    }
    string name = getStr("Enter Product Name: ");
    print("---------------------------------");
    print("[1] - Food");
    print("[2] - Drink");
    print("[3] - Clothing");
    print("[4] - Medical Supply");
    print("---------------------------------");
    string type = getStr("Enter the item type: ");
    switch (type[0]) {
        case '1':
            type = "Food";
            break;
        case '2':
            type = "Drink";
            break;
        case '3':
            type = "Clothing";
            break;
        case '4':
            type = "Medical Supply";
            break;
        default:
            print("Invalid Choice");
            addstock();
            pauseProgram();
    }
    string stock = getStr("Enter the Number Stock in the Inventory: ");
    string inventory = "\n" + barcode + SEPERATOR + name + SEPERATOR + type + SEPERATOR + stock + SEPERATOR;
    bool isSuccess = appendFile("inventory.csv", inventory);
    if (isSuccess) {
        print("Contact added successfully!");
        vector<string> row = {barcode, name, type, stock};
        csvData[barcode] = row;
        csvData[type] = row;
    } else
        print("Failed to add contact!");
    pauseProgram();
    start();
}

//The main menu of the program
void start() {
    bool exit = false;
    while (!exit) {
        system("cls");
        print("---------------------------------");
        print("W.E.G.A INVENTORY MANAGEMENT SYSTEM");
        print("---------------------------------");
        print("[1] - View Stocks");
        print("[2] - Update Stock");
        print("[3] - Add New Product");
        print("[4] - Remove Product");
        print("[5] - Quit");
        print("---------------------------------");
        string choice1 = getStr("Enter your choice: ");
        switch (choice1[0]) {
            case '1':
                viewstock();
                break;
            case '2':
                updatestock();
                break;
            case '3':
                addstock();
                break;
            case '4':
                removestock();
                break;
            case '5':
                exit = false;
                print("Closing Program...");
                break;
            default:
                print("Invalid Choice");
                pauseProgram();
                start();
                break;
        }
    }
}

//This is where the database file was initialize
int main() {
    std::vector<int> indexes = {0, 1};
    init("inventory.csv", csvData, indexes);
    start();
    return 0;
}
