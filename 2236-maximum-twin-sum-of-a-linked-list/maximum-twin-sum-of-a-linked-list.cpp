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
    int pairSum(ListNode* head) {
        ListNode* middle=head;
        ListNode* fast=head;
        ListNode* prev=NULL;

        while(fast && fast->next){
            prev=middle;
            middle=middle->next;
            fast=fast->next->next;
        }

        ListNode* prev2=NULL;
        ListNode* curr=middle;

        ListNode* last=curr;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev2;
            prev2=curr;
            if(curr) last=curr;
            curr=temp;
        }

        prev->next=prev2;

        ListNode* temp=head;
        int maxSum=INT_MIN;
        while(last){
            int sum=(temp->val+last->val);
            maxSum=max(sum,maxSum);
            last=last->next;
            temp=temp->next;
        }

        return maxSum;
    }
};