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
    bool containsOne(TreeNode* root) {
        if (!root)
            return false;
        
        bool left = containsOne(root->left);
        bool right = containsOne(root->right);
        
        if (!left)
            root->left = NULL;
        
        if (!right)
            root->right = NULL;
        
        return (root->val == 1) or left or right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {        
        if (containsOne(root))
            return root;
        
        return NULL;
    }
};