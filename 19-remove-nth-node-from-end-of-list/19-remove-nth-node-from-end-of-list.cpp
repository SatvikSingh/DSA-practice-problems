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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = NULL, *fast = head;
        int count = 1;
        
        while (count != n) {
            fast = fast->next;
            count++;
        }
        
        while (fast and fast->next) {
            if (!slow)
                slow = head;
            else
                slow = slow->next;
            
            fast = fast->next;
        }
        
        if (!slow and head->next)
            return head->next;
        else if (!slow)
            return NULL;
        
        slow->next = slow->next->next;
        
        return head;
    }
};