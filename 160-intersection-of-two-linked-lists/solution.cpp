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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        if(headA==headB) return headA;
        ListNode* first=headA;
        ListNode* second=headB;
        while(first!=second){
            first = (first != NULL) ? first->next : headB;
            second = (second != NULL) ? second->next : headA;
        }
        return first;
    }
};