<!-- header -->

# Final Exam/Project in Computer Programming online
- The following are divided into different branches. Each branch is a different project. Here are the project branches
    - [Student Record Management system](https://github.com/Angelo11199/comproFinal/tree/student-record-management-system)
    - [Bank Management system](https://github.com/Angelo11199/comproFinal/tree/bank-management-system)
    - [Contact Management system](https://github.com/Angelo11199/comproFinal/tree/contact-management-system)

- We used boilerplate codes to make it easier for you to code. [Click here to see the boilerplate codes](#boilerplate-codes) made by yours trully, Ice cream. (Angelo11199)


<!-- create a easy navigation -->
Table of Contents (Coding guides)
=================
- [prerequisites](#prerequisites)
- [boilerplate codes](#boilerplate-codes)
- [notes](#notes)
- [guides](#guides)

## prerequisites
- Here are the environment settings and requirements for this project.
 1. MinGW (gcc) [Download guide](https://code.visualstudio.com/docs/cpp/config-mingw)
 1. git [Download Link](https://github.com/git-for-windows/git/releases/download/v2.42.0.windows.2/Git-2.42.0.2-64-bit.exe)
 1. vscode
    1. vscode extensions
        1. C/C++
        1. C/C++ Extension Pack
- fork the repository. [(click here)](https://github.com/Angelo11199/comproFinal/fork). Click create Fork.

## boilerplate codes
1. `print(any Value)` : print a line WITH newline
1. `printLn(any Value)` : print a line WITHOUT newline
3. `getNum(string Prompt)` : get a number from the user and returns it as an int. (parameter: ` string prompt`). Will keep asking until a valid number is entered.
4. `getStr(string Prompt)` : get a string from the user and returns it as a string. (parameter: ` string prompt`).

example usage:

```cpp
#include "../include/snippets.h"  //ALWAYS ADD THIS
using namespace std;
int main() {
    printLn("Hello World! on the first line || ");
    print("this is on a same line");
    print("");  // to print a newline
    int num = getNum("Enter a number:");
    print("You entered: " + to_string(num));
    string str = getStr("Enter a string:");
    print("You entered: " + str);
    return 0;
}
```

output:

```
Hello World! on the first line || this is on a same line

Enter a number:1231
You entered: 1231
Enter a string:1231
You entered: 1231
```

## notes
1. two person per system. 
1. ALWAYS Add `#include "../include/snippets.h" ` to the top of your code. for you to use the snippets.
2. no need to add `#include <iostream>` to your code.
3. this is just for convenience. you can always add your own snippets. on `snippets.h` file. (or just tell me)

## Guides
- [Contact Management system](/guides/contactMangagementSystem.md)
- [Bank Management system](/guides/bankManagementSystem.md)
- [Student Record Management system](/guides/studentRecordManagementSystem.md)
