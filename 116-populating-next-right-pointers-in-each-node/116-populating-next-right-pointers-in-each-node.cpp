/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<vector<Node*>> level;
        queue<Node*> q;
        
        if (!root)
            return NULL;
        
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<Node*> temp_level;
            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                q.pop();
                
                temp_level.push_back(temp);
            
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);   
            }
            
            level.push_back(temp_level);
        }
        
        for (auto i : level) {
            for (auto j = 0; j < i.size()-1; j++) {
                if (j == i.size()-1)
                    i[j]->next = NULL;
                
                i[j]->next = i[j+1];
            }
        }
        
        return root;
    }
};