/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        vector<int> ans;
        unordered_map<TreeNode*, bool> visited;
        unordered_map<TreeNode*, TreeNode*> parent;
        
        q.push(root);
        visited[root] = false;
        parent[root] = NULL;
        
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            
            if (temp->left) {
                parent[temp->left] = temp;
                q.push(temp->left);
                visited[temp->left] = false;
            }
            
            if (temp->right) {
                parent[temp->right] = temp;
                q.push(temp->right);
                visited[temp->right] = false;
            }
        }
        
        int distance = 0;
        
        q.push(target);
        
        while (!q.empty()) {
            if (distance == k)
                break;
            
            int n = q.size();
            
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                visited[temp] = true;

                if (temp->left and !visited[temp->left]) {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }

                if (temp->right and !visited[temp->right]) {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }

                if (parent[temp] and !visited[parent[temp]]) {
                    q.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
            
            distance++;
        }
        
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};