/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* curr = head;
        int count = 0;
        
        while (curr) {
            s.push(curr);
            count++;
            curr = curr->next;
        }
        
        curr = head;
        
        for (int i = 0; i < count/2; i++) {
            ListNode* temp = s.top();
            s.pop();
            
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }
        
        curr->next = NULL;
    }
};