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
    ListNode* findMiddleNode(ListNode* head){
        ListNode* slow = head, *fast =head, *prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return prev;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* p = nullptr, *q = nullptr, *r = head;
        while(r){
            q = r;
            r= r->next;
            q->next =p;
            p=q;
        }
        return p;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return ; 
        
        ListNode* middle = findMiddleNode(head);
        ListNode* head2 = reverseList(middle->next);//middle->next remember
        middle->next = nullptr;

        ListNode* node = new ListNode(-1);
        ListNode* dummy = node;

        while(head && head2){
            dummy->next = head;
            dummy = dummy->next;
            head = head->next;
            dummy->next = head2;
            dummy= dummy->next;
            head2 = head2->next;
        }
        if(head) dummy->next = head;
        else dummy->next = head2;
        head = node->next;

    }
};
