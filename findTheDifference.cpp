class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for(int i = 0; i < s.size(); i++) {
            res ^= (s[i] ^ t[i]);
        }
        return res ^ t[s.size()];
    }
};
