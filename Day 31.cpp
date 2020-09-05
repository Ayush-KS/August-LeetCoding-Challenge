// Delete Node in a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root -> val > key) {
            root -> left = deleteNode(root -> left, key);
        } else if(root -> val < key) {
            root -> right = deleteNode(root -> right, key);
        } else {
            if(!root -> left && !root -> right)
                return NULL;
            if(!root -> right)
                return root -> left;
            if(!root -> left)
                return root -> right;
            
            TreeNode* toDelete = root -> left;
            while(toDelete -> right) {
                toDelete = toDelete -> right;
            }
            root -> val = toDelete -> val;
            root -> left = deleteNode(root -> left, toDelete -> val);
        }
        
        return root;
    }
};