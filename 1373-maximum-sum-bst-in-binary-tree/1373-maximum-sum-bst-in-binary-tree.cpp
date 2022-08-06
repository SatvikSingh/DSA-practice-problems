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
int ans;
class NodeSum {
public:
    int sum, max_node, min_node;
    
    NodeSum(int sum, int max_node, int min_node) {
        this -> sum = sum;
        this -> max_node = max_node;
        this -> min_node = min_node;
    }
};

class Solution {
public:
    NodeSum helper(TreeNode* root) {
        if (!root) 
            return NodeSum(0, INT_MIN, INT_MAX);
        
        NodeSum left = helper(root->left);
        NodeSum right = helper(root->right);
        
        if (left.max_node < root->val and right.min_node > root->val) {
            ans = max(ans, left.sum + right.sum + root->val);
            return NodeSum(left.sum + right.sum + root->val, max(root->val, right.max_node), min(root->val, left.min_node));
        }
        
        ans = max(ans, max(left.sum, right.sum));
        return NodeSum(max(left.sum, right.sum), INT_MAX, INT_MIN);
    }
    
    int maxSumBST(TreeNode* root) {
        ans = 0;
        helper(root);
        
        return ans;
    }
};