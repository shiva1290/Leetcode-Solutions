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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* temp = head;
        ListNode* first = nullptr;
        ListNode* last = nullptr;
        int count1 = 0;
        int count2 = 0;
        while (temp) {
            count1++;
            count2++;

            if (count1 == left - 1) {
                first = temp;
            }
            if (count2 == right + 1) {
                last = temp;
            }
            temp = temp->next;
        }

        ListNode* prev = last;
        ListNode* curr = (left == 1) ? head : first->next;

        while (curr != last) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        if (left == 1) {
            head = prev;
        } else {
            first->next = prev;
        }

        return head;
    }
};