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
typedef long long ll;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        
        if (!root)
            return 0;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            int cur_min = q.front().second;
            long long n = q.size(), left, right;
            
            for (long long i = 0; i < n; i++) {
                TreeNode* node = q.front().first;
                long long idx = q.front().second - cur_min;
                q.pop();
                
                if (i == 0)
                    left = idx;
                if (i == n-1ll)
                    right = idx;
                
                ll temp = 2ll*idx;
                
                if (node->left)
                    q.push({node->left, temp+1ll});
                if (node->right)
                    q.push({node->right, temp+2ll});
            }
            
            ans = max(ans, right-left+1ll);
        }
        
        return ans;
    }
};