//Language used: C++

class Solution {
public:
    int mySqrt(int x) {
        double x1 = x;
        
        while(abs((x1 * x1) - x) > 0.0001) {
            x1 = (x1 + x / x1) / 2;
        }
        return x1;
    }
};
