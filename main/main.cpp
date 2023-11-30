#include <iostream>

#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;
#include "../include/systems.h"
int main() {
    while (true) {
        startBankManagement();
        startContactManagement();
        system("cls");
    }
    return 0;
}