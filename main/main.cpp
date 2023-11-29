#include "../include/snippets.h"
using namespace std;
#include <conio.h>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#define PINDIGITS 6

void viewstock(){
    system("cls");
    print("---------------------------------");
    print("VIEWING INVENTORY");
    print("---------------------------------");
    print("[1] - Find Specific Product");
    print("[2] - View All");
    print("[3] - Go Back");
    print("---------------------------------");
    string choice2 = getStr("Enter your choice: ");
    switch(choice2[0]){
        case '1':
            removestock();
            break;
        case '2':
            exit = false;
            print("Closing Program......");
        case '3':
            goto start;
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
    tring record = rollNumber + SEPERATOR + fullName + SEPERATOR + contact + SEPERATOR + yearLevel + SEPERATOR + course + SEPERATOR + email + "\n";
    bool isSuccess = appendFile(fileName, record);
    if (isSuccess) {
        print("Contact added successfully!");
        vector<string> row = {rollNumber, last, first, middle, contact, yearLevel, course, email};
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
    string
}

int main(){
    start:
    std::vector<int> indexes = {0, 1};
    init("inventory.csv", csvData, indexes);
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
                goto start;
                break;
        }
    }
    return 0;
}
