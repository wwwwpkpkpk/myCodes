class Solution {
public:
    int divide(int dividend, int divisor) {
        long int quotient = 0;
        long long int dvo = divisor, remainder = dividend;
        
        if(dvo < 0) {
            dvo = dvo * -1;
        }
        if(remainder < 0) {
            remainder = remainder * -1;
        }
        
        dvo <<= 32;

        if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }else if(divisor == 1) {
            return dividend;
        }else if (dividend == divisor) {
            return 1;
        }

        while(abs(dvo) >= abs(divisor)) {
            remainder = remainder - dvo;
            if(remainder >= 0) {
                quotient <<= 1;
                quotient += 1;
            }else if(remainder < 0) {
                remainder = remainder + dvo;
                quotient <<= 1;
            }
            dvo >>= 1;
        }
        
        if(dividend < 0) {
            if(divisor > 0) {
                quotient *= -1;
            }
        }else if(dividend > 0) {
            if(divisor < 0) {
                quotient *= -1;
            }
        }

        return quotient;
    }
};
