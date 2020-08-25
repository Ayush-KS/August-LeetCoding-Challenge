// Sum of Left Leaves

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        
        if(root -> left && (!(root -> left -> left) && !(root -> left -> right))) {
            ans += root -> left -> val;
        } 
        
        ans += (sumOfLeftLeaves(root -> right) + sumOfLeftLeaves(root -> left));
        return ans;
    }
};   