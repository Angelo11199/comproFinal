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
    print("VIEWING RECORD");
    print("---------------------------------");
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
}

void removestock(){
    system("cls");
    print("---------------------------------");
    print("REMOVING STOCK");
    print("---------------------------------");
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
                    goto start;
                    break;
            }
        }
        return 0;
}
