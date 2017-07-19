class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int begin = 0, end = numbers.size() - 1, sum;
        
        while(begin < end) {
            if(numbers[begin] + numbers[end] == target) {
                res.push_back(begin + 1);
                res.push_back(end + 1);
                return res;
            } else if(numbers[begin] + numbers[end] < target) {
                begin++;
            } else {
                end--;
            }
        }
        
    }
};
