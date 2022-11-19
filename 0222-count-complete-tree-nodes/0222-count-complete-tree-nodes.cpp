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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        
        int left_h = 1, right_h = 1;
        TreeNode *temp_left = root, *temp_right = root;
        
        while (temp_left = temp_left->left) {
            left_h++;
        }
        
        while (temp_right = temp_right->right) {
            right_h++;
        }
        
        if (left_h == right_h)
            return pow(2, left_h)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};