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
    TreeNode* helper(vector<int>& preorder, int& curr, int bound) {
        if (curr == preorder.size() or preorder[curr] > bound) 
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[curr]);
        curr++;
        
        root->left = helper(preorder, curr, root->val);
        root->right = helper(preorder, curr, bound);
        
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int curr = 0;
        return helper(preorder, curr, INT_MAX);
    }
};