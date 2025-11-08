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
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current=head;
    if(!head || !head->next) return head;
    ListNode* unique=head->next;
    while(current && unique){
        while(unique!=nullptr && current->val==unique->val)
        {
            unique=unique->next;
        }
        current->next=unique;
        if(current){
        current=current->next;
        }
    }
    return head;
    }
};