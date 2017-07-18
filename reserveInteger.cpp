class Solution {
public:
    int reverse(int x) {
        long long int res = 0;
        int temp = abs(x);
        while(temp) {
            res = res*10 + temp%10;
            temp/= 10;
        }
        
        if(res < INT_MIN || res > INT_MAX) {
            return 0;
        }
        
        if(x < 0) {
            res = res * -1;
        }
        
        return res;
    }
};
