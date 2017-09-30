class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> map;
        int res = 0;
        
        while(n != 1) {
            if(map[n] == 0){
                map[n]++;
            }else {
                return false;
            }
            res = 0;
            while(n != 0) {
                res += (n%10)*(n%10);
                n /= 10;
            }
            
            n = res;
        }
        return true;
    }
};
