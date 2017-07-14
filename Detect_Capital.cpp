//Language used: C++

class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        
        for(int i = 1; i < word.length(); i++) {
            if(word[i] >= 'a' && word[i] <= 'z') {
                count += 1;
            } else {
                count += 2;
            }
        }
        
        if(count == word.length() - 1) {
            return true;
        } else if(count == 2 * (word.length() - 1)) {
            return word[0]>='A'&& word[0]<='Z';
        }else {
            return false;
        }
    }
};
