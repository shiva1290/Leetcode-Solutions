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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* orig=head;
        ListNode* store=head->next;

        ListNode* odd=head;
        ListNode* even=head->next;
        
        while(even && even->next){
            ListNode* nxt=even->next;
            odd->next=nxt;
            even->next=nxt->next;
            odd=nxt;
            even=nxt->next;
        }
        odd->next=store;
        return orig;
    }
};