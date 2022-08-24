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
    void dfs(TreeNode* root, unordered_map<int, vector<int>>& adjList, int parent) {
        if (!root)
            return;
        
        if (root->left)
            adjList[root->val].push_back(root->left->val);
        if (root->right)
            adjList[root->val].push_back(root->right->val);
        
        if (parent != -1)
            adjList[root->val].push_back(parent);
        
        dfs(root->left, adjList, root->val);
        dfs(root->right, adjList, root->val);
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int count = 0;
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, bool> infected;
        queue<int> q;
        
        dfs(root, adjList, -1);
        
        infected[start] = true;
        q.push(start);
        
        while (!q.empty()) {
            int n = q.size();
            // cout << count << " " << n << " ";
            for (int i = 0; i < n; i++) {
                int temp = q.front();
                // cout << temp << " " << adjList[temp].size() << " ";
                q.pop();
                
                for (int j = 0; j < adjList[temp].size(); j++) {
                    if (infected[adjList[temp][j]] == false) {
                        q.push(adjList[temp][j]);
                        infected[adjList[temp][j]] = true;    
                    }
                }
            }
            count++;
        }
        
        return count-1;
    }
};