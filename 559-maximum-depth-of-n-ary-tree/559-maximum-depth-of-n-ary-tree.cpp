/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
         if (!root)
             return 0;
        
        int max_h = 0;
        
        for (int i = 0; i < root->children.size(); i++) {
            max_h = max(max_h, maxDepth(root->children[i]));
        }
        
        return max_h+1;
    }
};