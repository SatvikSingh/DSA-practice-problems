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
    long long ans = 0;
    void helper(TreeNode* root, long long target) {
        if (!root)
            return;
        
        if (root->val == target)
            ans++;
        
        helper(root->left, target - root->val);
        helper(root->right, target - root->val);
    }
    
    int pathSum(TreeNode* root, long long targetSum) {
        if (root) {
            helper(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        
        return ans;
    }
};