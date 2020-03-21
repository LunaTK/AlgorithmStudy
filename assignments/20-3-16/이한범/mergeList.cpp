/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mergedList = NULL;
        ListNode* first = NULL;
        
        while(l1 && l2){
            if(l1->val < l2->val) {
                if(first == NULL) {
                    first = l1;
                    mergedList = l1;
                    l1 = l1->next;
                    continue;
                }
                mergedList->next = l1;
                l1 = l1->next;
                mergedList = mergedList->next;
            }
            else {
                if(first == NULL) {
                    first = l2;
                    mergedList = l2;
                    l2 = l2->next;
                    continue;
                }
                mergedList->next = l2;
                l2 = l2->next;
                mergedList = mergedList->next;
            }
        }
        if(l1) {
            if(first) mergedList->next = l1;
            else first = l1;
        }
        else {
            if(first) mergedList->next = l2;
            else first = l2;
        }
        
        return first;
    }
};
