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
    map<int, int> map;
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int start, int end, int& idx) {
        if (start > end)
            return NULL;
        
        int root_pos = map[postorder[idx]];
        
        TreeNode* root = new TreeNode(inorder[root_pos]);
        
        idx--;
        root->right = helper(inorder, postorder, root_pos+1, end, idx);
        root->left = helper(inorder, postorder, start, root_pos-1, idx);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size(), idx = postorder.size()-1;
        
        for (int i = 0; i < n; i++) {
            map[inorder[i]] = i;
        }
        
        return helper(inorder, postorder, 0, n-1, idx);
    }
};