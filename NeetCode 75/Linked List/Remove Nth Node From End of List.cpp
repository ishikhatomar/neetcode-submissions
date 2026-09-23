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
    int listLength(ListNode* head){
        int cnt =0;
        ListNode* p =head;
        while(p){
            cnt++;
            p=p->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return nullptr;
        int len = listLength(head);
        if(len == n) return head->next;
        int k = len-n-1;
        ListNode* p = head;
        while(k--){
            p=p->next;
        }
        p->next = p->next->next;
        return head;
    }
};
