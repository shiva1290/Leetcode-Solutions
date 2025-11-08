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
    ListNode* removeElements(ListNode* head, int target) {
        while (head && head->val == target) {
            ListNode* del = head;
            head = head->next;
            delete del;
        }
        if (!head) return NULL;

        ListNode* temp = head;
        while (temp->next) {
            if (temp->next->val == target) {
                temp->next = temp->next->next;
            }
            else temp = temp->next;
        }
        return head;
    }
};