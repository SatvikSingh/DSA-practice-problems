/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
        vector<Node*> neighbors;
        Node* new_node = new Node(node->val);
        map[node] = new_node;
        
        for (auto i : node->neighbors) {
            if (map.find(i) != map.end())
                neighbors.push_back(map[i]);
            else
                neighbors.push_back(dfs(i, map));
        }
        
        new_node->neighbors = neighbors;
        return new_node;
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        
        if (node == NULL)
            return NULL;
        
        if (node->neighbors.size() == 0) {
            Node* new_node = new Node(node->val);
            return new_node;
        }
        
        return dfs(node, map);
    }
};