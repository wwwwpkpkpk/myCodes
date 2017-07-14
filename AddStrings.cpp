Language used: C++

class Solution {
public:
    string addStrings(string num1, string num2) {
        int size1 = num1.length() - 1, size2 = num2.length() - 1;
        int carry = 0;
        int sum;
        string res;
        
        while(size1 >= 0 || size2 >= 0 || carry == 1) {
            sum = 0;
            if(size1 >= 0) sum += num1[size1] - '0';
            if(size2 >= 0) sum += num2[size2] - '0';
            sum += carry;
            if(sum >= 10) {
                carry = 1;
                res += sum % 10 + '0';
            } else {
                res += sum + '0';
                carry = 0;
            }
            size1--;
            size2--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
