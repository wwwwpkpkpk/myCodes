class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        
        if(timeSeries.empty()) {
            return 0;
        }
        
        res = timeSeries[timeSeries.size() - 1] - timeSeries[0] + duration;
        for(int i = 1; i < timeSeries.size(); i++) {
            res -= max(0, timeSeries[i] - (timeSeries[i - 1] + duration));
        }
        
        return res;
    }
};
