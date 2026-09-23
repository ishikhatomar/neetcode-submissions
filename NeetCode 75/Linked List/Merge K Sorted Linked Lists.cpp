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
    typedef pair<int,ListNode*> P;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<P, vector<P>, greater<P>> pq;
        for(ListNode* head: lists){
            if(head) //IMP what if head is null? there will be no value
                pq.push({ head->val, head});   
        }

        ListNode* node = new ListNode(-1);
        ListNode* dummy = node;
        //N nodes -> N iterations
        while(!pq.empty()){//runs once for every node
            ListNode* head = pq.top().second;
            pq.pop();//O(log K)
            if(head->next)
                pq.push({head->next->val, head->next});//O(log K)

            dummy->next = head;
            dummy=dummy->next;
        }
        return node->next;
    }
};
//TC = N × O(log K); pq size is atmost k i.e. no of lists and 
//K = number of linked lists
//N = total number of nodes across all K lists
