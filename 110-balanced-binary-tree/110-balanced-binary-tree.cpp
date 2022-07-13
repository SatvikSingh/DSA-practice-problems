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
    int helper(TreeNode* root, bool& ans) {
        if (!root)
            return 0;
        
        if (ans == false)
            return 0;
        
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        
        if (abs(left-right) > 1)
            ans = false;
        
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        helper(root, ans);
        
        return ans;
    }
};