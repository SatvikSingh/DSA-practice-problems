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
    // int sum = 0;
    
    void helper(TreeNode* root, int& sum) {
        if (!root) {
            return;
        }
        
        helper(root->right, sum);
        sum += root->val;
        root->val = sum;
        helper(root->left, sum);
        
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return NULL;
        
        int sum = 0;
        
        helper(root, sum);
        
        return root;
    }
};