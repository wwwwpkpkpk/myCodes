class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<string> M = {"", "M", "MM", "MMM"};
        vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        res += M[num/1000];
        res += C[(num%1000)/100];
        res += X[(num%100)/10];
        res += I[num%10];
        
        return res;
    }
};
