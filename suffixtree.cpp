#include <iostream>
#include <map>
#include <string>
using namespace std;

// Node structure for the Suffix Tree
struct SuffixTreeNode {
    map<char, SuffixTreeNode*> children;
    bool isEndOfWord;

    SuffixTreeNode() {
        isEndOfWord = false;
    }
};

// Suffix Tree class
class SuffixTree {
private:
    SuffixTreeNode* root;

    // Helper function to insert a suffix
    void insertSuffix(const string& suffix) {
        SuffixTreeNode* current = root;
        for (char ch : suffix) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new SuffixTreeNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

public:
    // Constructor to initialize the tree
    SuffixTree() {
        root = new SuffixTreeNode();
    }

    // Function to build the suffix tree for a given string
    void buildTree(const string& text) {
        for (size_t i = 0; i < text.length(); i++) {
            insertSuffix(text.substr(i));
        }
    }

    // Function to search for a pattern in the tree
    bool search(const string& pattern) {
        SuffixTreeNode* current = root;
        for (char ch : pattern) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }
};

int main() {
    SuffixTree tree;
    string text, pattern;

    cout << "Enter the text: ";
    cin >> text;

    tree.buildTree(text);

    cout << "Enter the pattern to search: ";
    cin >> pattern;

    if (tree.search(pattern)) {
        cout << "Pattern found in the text.\n";
    } else {
        cout << "Pattern not found in the text.\n";
    }

    return 0;
}

