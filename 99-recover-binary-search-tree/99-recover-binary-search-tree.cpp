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
    int i = 0;
    vector<int> temp;
    
    void dfs(TreeNode* root) {
        if (!root)
            return;
        
        dfs(root->left);
        temp.push_back(root->val);
        dfs(root->right);
    }
    
    void helper(TreeNode* root) {
        if (!root)
            return;
        
        helper(root->left);
        if (temp[i] != root->val)
            swap(temp[i], root->val);
        i++;
        helper(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        sort(temp.begin(), temp.end());
        helper(root);
        
        // for (auto i : temp) {
        //     cout << i << " ";
        // }
    }
};