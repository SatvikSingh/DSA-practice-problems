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
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> temp;
        helper(root, temp);
        
        int start = 0, end = temp.size()-1;
        
        while (start < end) {
            if (temp[start] + temp[end] == k)
                return true;
            else {
                if (temp[start] + temp[end] < k)
                    start++;
                else 
                    end--;
            }
        }
        
        return false;
    }
};