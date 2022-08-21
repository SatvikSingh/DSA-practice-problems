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
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> ans;
        if (start > end) {
            return {NULL};
        }
        
        if (start == end) {
            return {new TreeNode(start)};
        }
        
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = helper(start, i-1);
            vector<TreeNode*> right = helper(i+1, end);
            
            for (auto j : left) {
                for (auto k : right) {
                    ans.push_back(new TreeNode(i, j, k));
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans = helper(1, n);
        
        return ans;
    }
};