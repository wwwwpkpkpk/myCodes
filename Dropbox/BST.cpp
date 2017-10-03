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
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "BST.h"

using namespace std;

BSTree::BSTree() {
    root = NULL;
}

BSTree::~BSTree() {
    delete root->left;
    delete root->right;
    delete root;
}

void BSTree::BSTinsert(string newSymbol, bool newRflag, int newValue) {
    TreeNode *newNode;
    TreeNode *pWalk;
    TreeNode *parent;

    newNode = new TreeNode;
    newSymbol.resize(6);
    newNode->symbol = newSymbol;
	newNode->rFlag = newRflag;
	newNode->value = newValue;
    newNode->left = NULL;
    newNode->right=NULL;

    if(root == NULL) {
        root = newNode;
    }else {
        pWalk = root;

        while(pWalk != NULL) {
            parent = pWalk;
            if((newNode->symbol).compare(pWalk->symbol) < 0) {
                pWalk = pWalk->left;
            }else {
                pWalk = pWalk->right;
            }
        }

        if((newNode->symbol).compare(parent->symbol) < 0) {
            parent->left = newNode;
        }else {
            parent->right = newNode;
        }
    }
}

bool BSTree::Tsearch(string target, bool table) {
    return BSTsearch(root, target, table);
}

bool BSTree::BSTsearch(TreeNode *root, string target, bool table) {
    if(root == NULL) {
        return false;
    }else {
        if(root->symbol == target) {
            if(table == true) {

            } else {
                cout << "Found - display symbol " << root->symbol << " and all attributes: " << endl;
                cout << "Symbol      Value    RFlag   IFlag   MFlag" << endl;
                cout << root->symbol << setw(8) << root->value << setw(8) << root->rFlag << setw(8) << endl;
            }
            return true;
        }else {
            if(target.compare(root->symbol) > 0) {
                return BSTsearch(root->right, target, table);
            }else {
                return BSTsearch(root->left, target, table);
            }
        }
    }
}

void BSTree::subDisplay(TreeNode *Tptr) const {
    if(Tptr != NULL) {
        subDisplay(Tptr->left);
        cout << Tptr->symbol << setw(8) << Tptr->value << setw(8) << Tptr->rFlag << setw(8) << endl;
        subDisplay(Tptr->right);
    }
}

void BSTree::displayAll() const {
    if(root == NULL) {
        cout << "The tree is empty" << endl;
    }else {
        subDisplay(root);
    }
}
