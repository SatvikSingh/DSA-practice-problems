/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> map;
        Node* temp = head;
        
        while (temp) {
            map[temp] = new Node(temp -> val);
            temp = temp -> next;
        }
        
        temp = head;
        
        while (temp) {
            map[temp] -> next = map[temp -> next];
            map[temp] -> random = map[temp -> random];
            temp = temp -> next;
        }
        
        return map[head];
    }
};