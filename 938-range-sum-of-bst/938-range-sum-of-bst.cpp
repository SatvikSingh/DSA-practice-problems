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
    void helper(TreeNode* root, int low, int high, int& sum) {
        if (!root)
            return;
        
        helper(root->left, low, high, sum);
        if (root->val >= low and root->val <= high)
            sum += root->val;
        helper(root->right, low, high, sum);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        
        if (!root)
            return 0;
        
        helper(root, low, high, sum);
        
        return sum;
    }
};