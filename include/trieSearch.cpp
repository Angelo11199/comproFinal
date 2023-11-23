#include <iostream>
using namespace std;
#define LETTERS 26
struct trieNode {
    /* data */
    trieNode *child[LETTERS];
    bool isEnd;
};

trieNode *createNode() {
    trieNode *newNode = new trieNode;
    newNode->isEnd = false;
    for (int i = 0; i < LETTERS; i++) {
        newNode->child[i] = NULL;
    }
    return newNode;
}

char *insert(trieNode *root, string s) {
    trieNode *curr = root;
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        if (curr->child[index] == NULL) {
            curr->child[index] = createNode();
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
    return "Inserted";
}

char *search(trieNode *root, string s) {
    trieNode *curr = root;
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        if (curr->child[index] == NULL) {
            return "Not Found";
        }
        curr = curr->child[index];
    }
    if (curr->isEnd) {
        return "Found";
    }
    return "Not Found";
}

bool deleteWord(trieNode *root, string s, int i) {
    if (i == s.length()) {
        if (root->isEnd) {
            root->isEnd = false;
            return true;
        }
        return false;
    }
    int index = s[i] - 'a';
    if (root->child[index] == NULL) {
        return false;
    }
    bool shouldDelete = deleteWord(root->child[index], s, i + 1);
    if (shouldDelete) {
        delete root->child[index];
        root->child[index] = NULL;
        for (int i = 0; i < LETTERS; i++) {
            if (root->child[i] != NULL) {
                return false;
            }
        }
        return true;
    }
    return true;
}

int main() {
    trieNode *root = createNode();
    cout << insert(root, "hello") << endl;
    cout << insert(root, "hell") << endl;
    cout << insert(root, "help") << endl;
    cout << insert(root, "helps") << endl;
    cout << insert(root, "helping") << endl;
    cout << insert(root, "helped") << endl;
    cout << insert(root, "helpful") << endl;
    cout << insert(root, "helpfully") << endl;
    cout << insert(root, "helpfulness") << endl;
    cout << insert(root, "helplessness") << endl;
    cout << insert(root, "helpless") << endl;
    cout << insert(root, "helplessly") << endl;
    cout << insert(root, "helplessness") << endl;
    cout << insert(root, "helplessness") << endl;
    cout << search(root, "kill") << endl;
    cout << deleteWord(root, "help", 0) << endl;
    cout << search(root, "help") << endl;
}