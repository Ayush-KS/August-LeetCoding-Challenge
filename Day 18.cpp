// Numbers With Same Consecutive Differences

class Solution {
public:
    vector<int> ans;
    
    void helper(int n, int k, int num) {
        if(n == 0) {
            ans.push_back(num);
            return;
        }
        int lastDig = num % 10;
        if(lastDig + k < 10) {
            helper(n - 1, k, num*10 + lastDig + k);
        }
        if(lastDig - k >= 0 && (k)) {
            helper(n - 1, k , num*10 + lastDig - k);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1; i < 10; i++) {
            helper(n - 1, k, i);
        }
        if(n == 1)
            ans.push_back(0);
        return ans;
    }
};