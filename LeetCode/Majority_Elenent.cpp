//Language used: C++

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> maps;
        
        for(int i = 0; i < nums.size(); i++) {
            ++maps[nums[i]];
            if(maps[nums[i]] > (nums.size() / 2)) {
                return nums[i];
            }
        }
    }
};
