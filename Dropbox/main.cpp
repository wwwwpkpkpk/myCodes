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
#include <string>
#include <algorithm>
#include <fstream>
#include <locale>
#include "BST.h"

using namespace std;

void getFilename(int , char *[], ifstream &, ifstream &);
void readFile(BSTree &, ifstream &);
void readSecFile(BSTree &, ifstream &);
bool isSymbolValid(string );
bool isNum(const string &s);
void expEval(string ) const;

int main(int argc, char *argv[])
{
    ifstream inFile1, inFile2;
    BSTree tList;

    //Get file name from command line or user defined data
    getFilename(argc, argv, inFile1, inFile2);

    readFile(tList, inFile1);

    readSecFile(tList, inFile2);

    inFile1.close();
    inFile2.close();
    return 0;
}

void getFilename(int argc, char *argv[], ifstream &file1, ifstream &file2) {
    string newFile;

    if(argc == 2) {
        newFile = argv[1];
    } else {
        cout << "Please enter the name of the files(filename.dat/txt): ";
        cin >> newFile;
    }

    file1.open("symtable.dat");
    file2.open(newFile.c_str());

    if(!file1 || !file2) {
        cout << "The input file is invalid please check: " << newFile << endl;
    }
}

bool isSymbolValid(string testStr) {
    for(unsigned int i = 0; i < testStr.length(); i++) {
        if(!isalnum(testStr[i])) {
            return false;
        }
    }
    return true;
}

bool isNum(const string &s) {
    string::const_iterator it = s.begin();
    while(it != s.end() && isdigit(*it)) {
        ++it;
    }
    return !s.empty() && it == s.end();
}

void readFile(BSTree &tList, ifstream &inFile1){
    string newStr, newRflag, strTemp;
    bool found;
    float newValue;
    int ascii;

    //read the input file line by line and insert values after checking data validation
    while(inFile1 >> newStr >> newRflag >> newValue) {
        //Check the first letter
        ascii = static_cast<int>(newStr[0]);
        if(ascii >= 48 && ascii <= 57) {
            cout << "ERROR - symbol must start with a letter: " << newStr << endl;
        }else {
            //Check maximum length of symbol
            if(newStr.length() > 16) {
                cout << "ERROR - symbol maximum length 16: " << newStr << endl;
            }else {
                //Check if symbol has previously defined
                newStr.resize(6);
                found = tList.Tsearch(newStr, true);
                if(found) {
                    cout << "ERROR - symbol previously defined: " << newStr << endl;
                }else {
                    //Check is value valid
                    if((static_cast<int>(newValue) * 10) != (newValue * 10)) {
                        cout << "ERROR - symbol " << newStr << " invalid value: " << newValue << endl;
                    }else {
                        //Check the rflag
                        strTemp = newRflag;
                        transform(strTemp.begin(), strTemp.end(), strTemp.begin(), ::toupper);
                        if(strTemp != "TRUE" && strTemp != "FALSE" && strTemp != "0" && strTemp != "1") {
                            cout << "ERROR - symbol " << newStr << " invalid rflag: " << newRflag << endl;
                        }else {
                            if(strTemp == "1" || strTemp == "TRUE") {
                                tList.BSTinsert(newStr, 1, newValue);
                            }else {
                                tList.BSTinsert(newStr, 0, newValue);
                            }
                        }
                    }
                }
            }
        }
    }
}

void readSecFile(BSTree &tList, ifstream &inFile2) {
    string newStr, strTemp;
    int ascii;

    while(inFile2 >> newStr) {
        strTemp = newStr;
        ascii = static_cast<int>(strTemp[0]);

        if(newStr.length() > 16) {
            cout << "ERROR - symbol maximum length 16: " << newStr << endl;
        }else {

        }
    }
}

void expEval(string s) const {
    if(strTemp[0] == '@') {
            cout << strTemp << " Indirect Addressing" << endl;
            }else if(strTemp[0] == '#') {
                cout << strTemp << " Immediate Addressing" << endl;
            }else if(strTemp[0] == '=') {
                if(strTemp[1] == 'C') {
                    cout << strTemp << " Character Literal" << endl;
                } else if(strTemp[1] == 'X') {
                    cout << strTemp << " Hexdecimal Literal" << endl;
                }
            } else {
                if(isNum(strTemp)) {
                    cout << strTemp << " Immediate Addressing" << endl;
                }else {
                    if(strTemp[strTemp.length() - 1] == 'X') {
                        cout << strTemp << " Indexed Addressing" << endl;
                    }else {
                        expEval(strTemp);
                    }
                }
            }
}
