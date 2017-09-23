class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, begin = 0, end = height.size() - 1;
        
        while(begin < end) {
            area = max(area, min(height[begin], height[end])*(end - begin));
            if(height[begin] < height[end]) {
                begin++;
            }else {
                end--;
            }
        }
        return area;
    }
};
