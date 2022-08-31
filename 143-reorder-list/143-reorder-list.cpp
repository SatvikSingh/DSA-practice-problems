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
        ListNode* slow = head, *fast = head->next;
        
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        
        ListNode* prev = NULL, *after = NULL;
        slow->next = NULL;
        
        while (mid) {
            after = mid->next;
            mid->next = prev;
            prev = mid;
            mid = after;
        }
        
        ListNode* curr1 = head, *curr2 = prev;
        
        while (curr2) {
            ListNode* temp1 = curr1->next;
            ListNode* temp2 = curr2->next;
            
            curr1->next = curr2;
            curr2->next = temp1;
            curr1 = temp1;
            curr2 = temp2;
        }
    }
};