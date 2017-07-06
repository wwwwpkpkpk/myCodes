//Language used: C++

class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR = x ^ y, dist = 0;
        
        while(XOR) {
            dist += XOR & 1;
            XOR >>= 1;
        }
        
        return dist;
    }
};
