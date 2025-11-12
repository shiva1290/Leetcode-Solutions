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
        if (!head || !head->next)
            return head;
        ListNode* dummy=new ListNode(0,head);
        ListNode* prev = dummy;
        ListNode* temp = head;
        while (temp) {
        bool duplicate=false;
            while (temp->next && temp->val == temp->next->val) {
                duplicate=true;
                temp=temp->next;
            }
            if(duplicate){
                prev->next=temp->next;
            }
            else {
                prev=prev->next;
            }
        temp=temp->next;
        }
        return dummy->next;
    }
};