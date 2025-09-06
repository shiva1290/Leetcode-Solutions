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
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head|| k==0 || !head->next){
            return head;
        }

        ListNode* temp=head;
        int counter=1;
        while(temp->next){
            temp=temp->next;
            counter++;
        }
        temp->next=head;

        k=k%counter;
        if(k==0){
            temp->next=NULL;
            return head;
        }

        ListNode* dummy=head;
        for(int i=0;i<counter-k-1;i++){
            dummy=dummy->next;
        }
        ListNode* newHead=dummy->next;
        dummy->next=NULL;
        return newHead;
    }
};