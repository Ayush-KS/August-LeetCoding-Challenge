// Sort Array By Parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int si = 0;
        int ei = n - 1;
        
        while(si < ei) {
            bool first = nums[si] & 1;
            bool last = nums[ei] & 1;
            if(!first) {
                si++;
            } else if(last) {
                ei--;
            } else {
                swap(nums[si], nums[ei]);
                si++;
                ei--;
            }
        }
        
        return nums;
    }
};