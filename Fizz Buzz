//Language used: C++

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        
        for(int i = 1; i <= n; i++) {
            
            if(i % 3 == 0 || i % 5 == 0) {
                if(i % 3 == 0) {
                    res[i-1] += string("Fizz");
                }
                if(i % 5 == 0) {
                    res[i-1] += string("Buzz");
                }
            } else {
                res[i-1] += to_string(i);
            }

        }
        
        return res;
    }
};
