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
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        
        return (1 + max(helper(root->left), helper(root->right)));
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};
        
        int h = helper(root);
        vector<vector<int>> ans(h);
        queue<TreeNode*> q;
        
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                
                temp.push_back(node->val);
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            
            ans[h-1] = temp;
            h--;
            temp.clear();
        }
        
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};