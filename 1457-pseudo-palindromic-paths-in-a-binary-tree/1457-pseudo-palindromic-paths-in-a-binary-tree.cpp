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
    int ans = 0;
    
    void helper(TreeNode* root, unordered_map<int, int>& map) {
        if (!root)
            return;
        
        map[root->val]++;
        
        if (!root->left and !root->right) {
            int count = 0;
            
            for (auto i : map) {
                if (i.second % 2 != 0)
                    count++;
            }
            
            if (count <= 1)
                ans++;
            
            map[root->val]--;
            return;
        }

        helper(root->left, map);
        helper(root->right, map);
        
        map[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if (!root)
            return 0;
        
        unordered_map<int, int> map;
        
        helper(root, map);
        
        return ans;
    }
};