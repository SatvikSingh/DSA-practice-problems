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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> map;
        
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int col = temp.second.first, row = temp.second.second;
            
            map[col][row].insert(node->val);
            
            if (node->left)
                q.push({node->left, {col-1, row+1}});
            if (node->right)
                q.push({node->right, {col+1, row+1}});
        }
        
        for (auto i : map) {
            vector<int> temp;
            for (auto j : i.second) {
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};