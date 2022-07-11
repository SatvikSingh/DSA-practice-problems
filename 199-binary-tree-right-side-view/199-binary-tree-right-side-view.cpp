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
    vector<int> helper(TreeNode* root, vector<int> &ans, int h) {
        if (root == NULL)
            return ans;
        
        if (h == ans.size())
            ans.push_back(root->val);
        
        ans = helper(root->right, ans, h+1);
        ans = helper(root->left, ans, h+1);
        
        return ans;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        ans = helper(root, ans, 0);
        return ans;
    }
};