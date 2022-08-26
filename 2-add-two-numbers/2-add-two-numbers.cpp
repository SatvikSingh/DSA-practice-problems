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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;
        int a = 0, b = 0;
        
        while (l1 or l2 or carry != 0) {
            if (l1)
                a = l1->val;
            else
                a = 0;
            
            if (l2)
                b = l2->val;
            else
                b = 0;
            
            int sum = carry + a + b;
            carry = sum/10;
            
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            
            if (l1)
                l1 = l1->next;
            else
                l1 = NULL;
            
            if (l2)
                l2 = l2->next;
            else
                l2 = NULL;
        }
        
        return dummy->next;
    }
};