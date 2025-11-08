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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }

        while(head && mpp[head->val]){
            head=head->next;
        }
        if(!head) return NULL;
        ListNode* temp=head;
    
        while(temp->next){
            ListNode* nextNode=temp->next;
            int val=nextNode->val;
            if(mpp[val]){
                if(nextNode->next){
                temp->next=nextNode->next;
                }
                else{
                    temp->next=nullptr;
                    break;
                }
            }
            else temp=temp->next;
        }
        return head;
    }
};