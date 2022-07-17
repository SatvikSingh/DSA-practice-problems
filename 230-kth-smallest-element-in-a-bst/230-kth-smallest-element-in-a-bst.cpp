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
    void helper(TreeNode* root, vector<int>& temp) {
        if (!root)
            return;
        
        helper(root->left, temp);
        temp.push_back(root->val);
        helper(root->right, temp);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        helper(root, temp);
        
        // for (auto i : temp)
        //     cout << i << " ";
        
        return temp[k-1];
    }
};