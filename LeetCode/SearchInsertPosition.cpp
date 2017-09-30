class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        int mid;
        
        while(begin <= end) {
            mid = (begin + end)/2;
            if(nums[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return begin;
    }
};
