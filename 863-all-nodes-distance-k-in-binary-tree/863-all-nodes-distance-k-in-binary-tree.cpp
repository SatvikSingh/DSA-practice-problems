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
    void dfs(TreeNode* root, int k, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
                // cout << k << " " << root->val << endl;

        if (k == 0) {
            ans.push_back(root->val);
            return;
        }
        
        dfs(root->left, k-1, ans);
        dfs(root->right, k-1, ans);
    }
    
    int helper(TreeNode* root, TreeNode* target, int k, vector<int>& ans) {
        if (root == NULL) {
            return -1;
        }
        if (root == target) {
            dfs(root, k, ans);
            return 1;
        }
        
        int left_distance = helper(root->left, target, k, ans);
        int right_distance = helper(root->right, target, k, ans);
        
        if (left_distance == -1 and right_distance == -1) {
            return -1;
        }
        
        if (k == left_distance or k == right_distance) {
            // cout << "het";
            ans.push_back(root->val);
            return max(left_distance, right_distance)+1;
        }
        
        if (left_distance != -1) {
            int temp = k-left_distance-1;
            dfs(root->right, temp, ans);
            return left_distance+1;
        }
        
        if (right_distance != -1) {
            dfs(root->left, k-right_distance-1, ans);
            return right_distance+1;
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        helper(root, target, k, ans);
        return ans;
    }
};