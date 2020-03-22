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
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode *result = new ListNode;
        ListNode *temp; 
        ListNode *l1temp;
        ListNode *l2temp;
        l1temp = l1;
        l2temp = l2;
        int flag1 = 0;
        int flag2 = 0;
        if(l1->val <= l2->val){
            result->val = l1->val;
            temp = result;
            if(l1->next == NULL){
                result->next = l2;
                return result;
            }
            l1temp = l1temp->next;
        }
        else{
            result->val = l2->val;
            temp = result;
            if(l2->next == NULL){
                result->next = l1;
                return result;
            }
            l2temp = l2temp->next;

        }
        while(1){
            if(l1temp->val >= l2temp->val){
                ListNode *inserted = new ListNode(l2temp->val);
                temp->next = inserted;
                if(l2temp->next == NULL){
                    temp->next->next = l1temp;
                    return result;
                }
                temp = temp->next;
                l2temp = l2temp->next; 
            }
            else{
                ListNode *inserted = new ListNode(l1temp->val);
                temp->next = inserted;
                if(l1temp->next == NULL){
                    temp->next->next = l2temp;
                    return result;
                }
                temp = temp->next;
                l1temp = l1temp->next;
            }
        }
    }
};
