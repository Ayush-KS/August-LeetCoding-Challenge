// Find Right Interval

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;
        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            mp[intervals[i][0]] = i;
        }
        
        vector<int> op(n, -1);
        
        for(int i = 0; i < n; i++) {
            auto in = mp.lower_bound(intervals[i][1]);
            if(in != mp.end()) {
                op[i] = in -> second;
            }
        }
        
        return op;
    }
};