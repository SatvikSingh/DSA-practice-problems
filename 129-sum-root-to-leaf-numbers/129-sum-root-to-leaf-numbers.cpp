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
    void helper(TreeNode* root, int curr_num, int& ans) {
        if (!root)
            return;
        
        curr_num = (curr_num*10) + root->val;
        
        if (!root->left and !root->right) {
            ans += curr_num;
        }
        
        helper(root->left, curr_num, ans);
        helper(root->right, curr_num, ans);
    } 
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        
        if (!root)
            return 0;
        
        helper(root, 0, ans);
        
        return ans;
    }
};