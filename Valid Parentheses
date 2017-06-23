//Language used: C++

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        char testP;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                myStack.push(s[i]);
            } 
            
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(myStack.empty()) {
                    return false;
                } else {
                    testP = myStack.top();
                    myStack.pop();
                    if((testP == '(' && s[i] != ')') || (testP == '[' && s[i] != ']') || (testP == '{' && s[i] != '}')) {
                        return false;
                    }
                }
            }
        }
        
        if(myStack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
