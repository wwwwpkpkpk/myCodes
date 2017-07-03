//Language used: C++

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        double b = 0;
        
        for(a = 0; a * a <= c; a++) {
            b = sqrt(c - a * a);
            if(b == (int)b) {
                return true;
            }
        }
        
        return false;
    }
};
