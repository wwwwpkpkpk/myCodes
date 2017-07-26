class Solution {
public:
    bool isPalindrome(int x) {
        int revNum = 0;
        if(x == 0) {
            return true;
        }
        
        if(x < 0 || x % 10 == 0) {
            return false;
        }
        while(x > revNum) {
            revNum = revNum * 10 + x % 10;
            x /= 10;
        }
        if(revNum == x || x == revNum/10) {
            return true;
        } else {
            return false;
        }
    }
};
