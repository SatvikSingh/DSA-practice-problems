/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;
        
        if (root == p or root == q)
            return root;
        
        TreeNode* r1 = dfs(root->left, p, q);
        TreeNode* r2 = dfs(root->right, p, q);
        
        if (r1 and r2) {
            return root;
        }
        else {
            if (r1)
                return r1;
            else
                return r2;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};