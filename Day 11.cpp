// H-Index

class Solution {
public:
    int hIndex(vector<int>& cit) {
        sort(cit.begin(), cit.end());
        int ans = 0;
        int n = cit.size();
        
        for(int i = 0; i < n; i++) {
            if(cit[n - i - 1] < (i + 1))
                break;
            if(cit[n - i - 1] >= (i + 1)) {
                ans = i + 1;
            }
        }
        return ans;
    }
};