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
    TreeNode *first, *last, *prev;
    
    void dfs(TreeNode* root) {
        if (!root)
            return;
        
        dfs(root->left);
        if (prev and root->val < prev->val) {
            if (!first) {
                first = prev;
                last = root;
            }
            else {
                last = root;
            }
        }
        prev = root;
        dfs(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        dfs(root);
        swap(first->val, last->val);
        // sort(temp.begin(), temp.end());
        // helper(root);
        
        // for (auto i : temp) {
        //     cout << i << " ";
        // }
    }
};