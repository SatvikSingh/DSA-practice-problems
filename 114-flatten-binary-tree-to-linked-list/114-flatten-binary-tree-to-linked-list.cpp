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
    void flatten(TreeNode* root) {
        if (!root)
            return;
        
        TreeNode* right = root->right;
        TreeNode* curr = root;
        
        root->right = root->left;
        root->left = NULL;
        
        while (curr->right) {
            curr = curr->right;
        }
        
        curr->right = right;
        flatten(root->right);
    }
};