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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        ListNode *prev = NULL, *temp = NULL;
        
        while (fast and fast->next) {
            fast = fast->next->next;
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        if (fast)
            slow = slow->next;
        else
            slow = slow;
        
        while (slow) {
            if (slow->val != prev->val) {
                return false;
            }
            
            prev = prev->next;
            slow = slow->next;
        }
        
        return true;
    }
};