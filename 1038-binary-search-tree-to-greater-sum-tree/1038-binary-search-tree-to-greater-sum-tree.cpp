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
    void helper(TreeNode* root, int& curr_sum) {
        if (!root)
            return;
        
        helper(root->right, curr_sum);
        curr_sum += root->val;
        root->val = curr_sum;
        helper(root->left, curr_sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        if (!root)
            return NULL;
        
        int curr_sum = 0;
        
        helper(root, curr_sum);
        
        return root;
    }
};