//Given an array of integers, return indices of the two numbers such that they add up to a specific target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.

/*
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int ans1 = 0, ans2 = 1;
        vector<int> ans;
        while(nums[ans1] + nums[ans2] != target && ans1 != nums.size() - 1) {
            ans2++;
            if(ans2 == nums.size() - 1 && nums[ans1] + nums[ans2] != target) {
                ans1++;
                ans2 = ans1+1;
            }
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};
