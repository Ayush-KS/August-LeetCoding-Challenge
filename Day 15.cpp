// Non-overlapping Intervals


static bool comparator(const vector<int>& v1, const vector<int>& v2) {
    if(v1[0] == v2[0])
        return v1[1] > v2[1];
    return v1[0] < v2[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), comparator);
        
        int n = intervals.size();
        
        int ans = 1;
        int nextMax = intervals[0][1];
        
        for(int i = 1; i < n; i++) {
            if(nextMax <= intervals[i][0]) {
                ans++;
                nextMax = intervals[i][1];
            } else {
                nextMax = min(nextMax, intervals[i][1]);
            }
        }
        
        return n - ans;
    }
};