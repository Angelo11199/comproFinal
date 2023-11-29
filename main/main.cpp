#include "../include/snippets.h"
using namespace std;
#include <conio.h>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#define PINDIGITS 6

void addstock(){
    system("cls");
    print("---------------------------------");
    print("ADDING NEW STOCK");
    print("---------------------------------");
    string barcode = getStr("Enter Bar Code: ");
    string name = getStr("Enter Product Name: ");
    print("---------------------------------");
    print("[1] - Food");
    print("[2] - Drink");
    print("[3] - Clothing");
    print("[4] - Medical Supply");
    print("---------------------------------");
    type:
    string type = getStr("Enter the item type: ");
    switch(type[0]){
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
            pauseProgram();
            goto type;
    }
    string stock = getStr("Enter the Number Stock in the Inventory: ");
    string inventory = barcode + SEPERATOR + name + SEPERATOR + type + SEPERATOR + stock + SEPERATOR + "\n";
    bool isSuccess = appendFile("inventory.csv", inventory);
    if (isSuccess) {
        print("Contact added successfully!");
        vector<string> row = {barcode, name, type, stock};
        csvData[barcode] = row;
        csvData[type] = row;
    } else
        print("Failed to add contact!");
    pauseProgram();
}

void removestock(){
    system("cls");
    print("---------------------------------");
    print("REMOVING STOCK");
    print("---------------------------------");
    string barcode = getStr("Enter Barcode: ");
    vector<string> result = getRow(barcode);
    deleteRow("inventory.csv", result[0]);
    print("Record deleted successfully!");
    pauseProgram();
}

void viewtype(){
    system("cls");
    print("---------------------------------");
    print("[1] - Food");
    print("[2] - Drink");
    print("[3] - Clothing");
    print("[4] - Medical Supply");
    print("---------------------------------");
    type1:
    string type = getStr("Enter the item type: ");
    switch(type[0]){
        case '1':
            type = "Food";
            vector<string> result = getRow(type);
            if (result.empty()) {
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");
                pauseProgram();
            } else {
                print("--------------------------------");
                print(result[1] + result[2]);
                print("--------------------------------");
            }
            break;
        case '2':
            type = "Drink";
            vector<string> result = getRow(type);
            if (result.empty()) {
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");
                pauseProgram();
            } else {
                print("--------------------------------");
                print(result[1] + result[2]);
                print("--------------------------------");
            }
            break;
        case '3':
            type = "Clothing";
            vector<string> result = getRow(type);
            if (result.empty()) {
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");
                pauseProgram();
            } else {
                print("--------------------------------");
                print(result[1] + result[2]);
                print("--------------------------------");
            }
            break;
        case '4':
            type = "Medical Supply";
            vector<string> result = getRow(type);
            if (result.empty()) {
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");
                pauseProgram();
            } else {
                print("--------------------------------");
                print(result[1] + result[2]);
                print("--------------------------------");
            }
            break;
        default:
            print("Invalid Choice");
            pauseProgram();
            goto type1;
    }
}

void viewstock(){
    system("cls");
    print("-----------------------------------");
    print("VIEWING INVENTORY");
    print("-----------------------------------");
    print("[1] - View Specific Product");
    print("[2] - View Specific Type of Product");
    print("[3] - Go Back");
    print("-----------------------------------");
    string choice2 = getStr("Enter your choice: ");
    switch(choice2[0]){
        case '1':
            string barcode = getStr("Enter Bar Code: ");
            vector<string> result = getRow(barcode);
            pauseProgram();
            system("cls");
            if (result.empty()) {
                print("--------------------------------");
                print("Record not found.");
                print("--------------------------------");
                pauseProgram();
                viewstock();
                break;
            } else {
                print("--------------------------------");
                print("Bar Code: " + result[0] + "\nProduct Name: " + result[1] + "\nType: " + result[2] + "\nMiddle Name: " + result[3]);
                print("--------------------------------");
            }
            break;
        case '2':
            viewtype();
            break;
        case '3':
            break;
        default:
            print("Invalid Choice");
            pauseProgram();
            viewstock();
            break;
    }    
}

void updatestock(){
    system("cls");
    print("---------------------------------");
    print("UPDATING RECORD");
    print("---------------------------------");
}

void start(){
    bool exit = false;
    while(!exit){
        system("cls");
        print("---------------------------------");
        print("W.E.G.A STORAGE MANAGEMENT SYSTEM");
        print("---------------------------------");
        print("[1] - View Stocks");
        print("[2] - Update Stock");
        print("[3] - Add New Product");
        print("[4] - Remove Product");
        print("[5] - Quit");
        print("---------------------------------");
        string choice1 = getStr("Enter your choice: ");
        switch(choice1[0]){
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
                print("Closing Program......");
                break;
            default:
                print("Invalid Choice");
                pauseProgram();
                start();
                break;
        }
    }
}

int main(){
    std::vector<int> indexes = {0, 1};
    init("inventory.csv", csvData, indexes);
    return 0;
}
