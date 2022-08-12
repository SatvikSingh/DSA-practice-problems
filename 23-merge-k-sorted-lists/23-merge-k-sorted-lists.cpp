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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<int> temp;
        
        if (n == 0)
            return NULL;
        
        for (auto list : lists) {
            if (list == NULL)
                continue;
            ListNode* curr_temp = list;
            while (curr_temp != NULL) {
                temp.push_back(curr_temp->val);
                curr_temp = curr_temp -> next;
            }
        }
        
        if (temp.size() == 0)
            return NULL;
        
        sort(temp.begin(), temp.end());
        
        ListNode* head = new ListNode(temp[0]);
        ListNode* curr = head;
        
        for (int i = 1; i < temp.size(); i++) {
            ListNode* node = new ListNode(temp[i]);
            curr -> next = node;
            curr = curr -> next;
        }
        
        return head;
    }
};