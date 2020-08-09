// Path Sum III

class Solution {
public:
    int ans = 0;
    
    void helper(TreeNode* root, int sum, unordered_map<int, int> prefix, int curr) {
        if(!root)
            return;
        
        curr += root -> val;
        ans += prefix[curr - sum];
        prefix[curr]++;

        helper(root -> left, sum, prefix, curr);
        helper(root -> right, sum, prefix, curr);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        
        unordered_map<int, int> prefix;
        prefix.reserve(1010);
        prefix[0] = 1;
        helper(root, sum, prefix, 0);
        return ans;
    }
};