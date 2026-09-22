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
        ListNode* node = new ListNode(-1);
        ListNode* dummy = node;
        ListNode* p = list1, *q = list2;
        while(p && q){
            if(p->val <= q->val){
                dummy->next = p;
                p=p->next;
            }
            else{
                dummy->next = q;
                q = q->next;
            }
            dummy = dummy->next;
        }
        if(p)
            dummy->next = p;
        if(q)
            dummy->next = q;

        return node->next;
        
    }
};
