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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        
        ListNode* tempHead = NULL;
        ListNode* tempTail = NULL;
        
        if (list1 -> val < list2 -> val) {
            tempHead = list1;
            tempTail = list1;
            list1 = list1 -> next;
        }
        else {
            tempHead = list2;
            tempTail = list2;
            list2 = list2 -> next;
        }
        
        while (list1 != NULL and list2 != NULL) {
            if (list1 -> val < list2 -> val) {
                tempTail -> next = list1;
                tempTail = tempTail -> next;
                list1 = list1 -> next;
            }
            else {
                tempTail -> next = list2;
                tempTail = tempTail -> next;
                list2 = list2 -> next;
            }
        }
        
        if (list1 != NULL) {
            tempTail -> next = list1;
            list1 = list1 -> next;
        }
        if (list2 != NULL) {
            tempTail -> next = list2;
        }
        
        return tempHead;
    }
};