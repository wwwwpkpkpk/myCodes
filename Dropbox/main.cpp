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
void expEval(BSTree , string );
void parse(string , string & , string & , char & , bool & );

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
        if(ascii < 65 || (ascii > 90 && ascii < 97) || ascii > 122) {
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
    
    while(inFile2 >> newStr) {
        strTemp = newStr;
        
        if(strTemp[0] != '#' || (strTemp[0] < '0' && strTemp[0] > '9') || (strTemp[0] < '@' && strTemp[0] > 'Z')) {
            cout << "ERROR - expression " << strTemp << " has invalid start" << endl;
        } else {
            if(strTemp.length() > 13) {
                cout << "ERROR - expression " << strTemp << " exceeds maximum length" << endl;
            }else {
                expEval(tList, strTemp);
            }
        }
    }
}

void expEval(BSTree tList, string s) {
    int addr = 0, num1 = 0, num2 = 0;
    char oprand = '\0';
    string temp = s;
    string sym1, sym2;
    bool split = false, dir = true, indir = false, imm = false, indx = false;
    
    
    /* Invalid Addressing: 
     #WHITE,X   ERROR
     @WHITE,X   ERROR
     @120       ERROR
     #100       VALID
     =X"012A"   ERROR
     =X'72A'    VALID
     =C"012A"   ERROR
     =C'012A'   VALID
    */
    
    if(temp[0] == '=') { // Literal
        temp.erase(temp.begin());
        if(temp[0] == 'C') {
            temp.erase(temp.begin());
            if(temp[0] == '\'' && temp[*temp.end()] == '\'') {
                // display literal table
                temp.erase(temp.begin(), temp.end());
                cout << temp << "  " << temp.length() << "  " << addr << endl;
                addr++;
            }else {
                cout << "ERROR - expression " << s << " with invalid literal format" << endl;
            }
        } else if(temp[0] == 'X') {
            temp.erase(temp.begin());
            if(temp[0] == '\'' && temp[*temp.end()] == '\'') {
                // display literal table
                temp.erase(temp.begin(), temp.end());
                cout << hex << temp << "  " << temp.length() << "  " << addr << endl;
                addr++;
            }else {
                cout << "ERROR - expression " << s << " with invalid literal format" << endl;
            }
        }
        
    }else {
        parse(temp, sym1, sym2, oprand, split);
        if(!split) {
            if(isNum(sym1) && isNum(sym2)) {
                cout << "ERROR - expression " << s << "has immediate addressing in indrect addressing" << endl;
            }else if(sym2[0] == '@' || sym2[0] == '#') {
                cout << "ERROR - expression" << s << " has operation within" << endl;
            } else {
                if(sym1[*sym1.end() - 1] == ',') {
                    cout << " ERROR - expression " << s  << " has invalid index addressing" << endl;
                }else {
                    if(sym1[0] == '@') {
                        dir = false; indir = true;
                    }else if(sym1[0] == '#') {
                        dir = false; imm = true;
                    }
                    
                    if(!tList.Tsearch(sym1, true)) {
                        if(!isNum(sym1)) {
                            cout << "ERROR - expression" << s << " not found in symbol table" << endl;
                        }else {
                            dir = false; imm = true;
                            cout << s <<  << endl;
                        }
                    }
                }
            }
        }
    }
    
    
}

void parse(string line, string &arg1, string &arg2, char &oprand, bool & split) {
    for(int i = 0; i < line.length(); i++) {
        if(line[i] == '+' || line[i] == '-') {
            split = true;
            oprand = line[i];
            line.erase(line.begin() + i);
        }
        if(!split) {
            arg1 += line[i];
        }else {
            arg2 += line[i];
        }
    }
}


