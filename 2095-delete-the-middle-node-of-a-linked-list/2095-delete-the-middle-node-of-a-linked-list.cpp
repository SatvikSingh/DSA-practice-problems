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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        ListNode* prev = NULL;
        
        while (fast and fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        if (!head->next)
            return NULL;
        else
            prev->next = prev->next->next;
        
        return head;
    }
};