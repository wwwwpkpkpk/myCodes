/********************************************************************
 *** NAME : Xiaozhu Jin                                           ***
 *** CLASS : CSc 354                                              ***
 *** ASSIGNMENT : 1                                               ***
 *** DUE DATE : 09/12/2017                                        ***
 *** INSTRUCTOR : Jason Werpy                                     ***
 ********************************************************************
 *** DESCRIPTION : This program will do the following tasks:      ***
 ***               1. Read symbol table file with command line    ***
 ***                  or user-defined data                        ***
 ***               2. Check validation of all symbols and their   ***
 ***                  attributes                                  ***
 ***               3. Read a file that contains symbols ready to  ***
 ***                  be search in the Binary Search Tree         ***
 ***               4. Search the symbol in Binary Search Tree     ***
 ***               5. Display all stored symbol and their         ***
 ***                  attributes                                  ***
 ********************************************************************/
#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct TreeNode {
    string symbol;
	bool rFlag;
    int value;
    /*
    bool indirect;
    bool immediate;
    bool indexed;
    */
    struct TreeNode *left;
    struct TreeNode *right;
};

class BSTree {
    public:
        BSTree();
        ~BSTree();
        void BSTinsert(string, bool, int);
        bool Tsearch(string , bool );
        bool BSTsearch(TreeNode * , string , bool );
        void displayAll() const;
        void subDisplay(TreeNode *) const;

    private:
        struct TreeNode *root;
};

#endif // BST_H
