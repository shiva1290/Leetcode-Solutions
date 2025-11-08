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
    ListNode* mergeTwo(ListNode* list1, ListNode* list2) {
        ListNode* first = list1;
        ListNode* second = list2;

        ListNode* newHead = new ListNode();
        ListNode* merged = newHead;

        while (first && second) {
            if (first->val <= second->val) {
                merged->next = first;
                first = first->next;
                merged = merged->next;
            } else {
                merged->next = second;
                second = second->next;
                merged = merged->next;
            }
        }
        while (first) {
            merged->next = first;
            first = first->next;
            merged = merged->next;
        }
        while (second) {
            merged->next = second;
            second = second->next;
            merged = merged->next;
        }
        return newHead->next;
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* helper(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;

        left = helper(left);
        right = helper(right);

        return mergeTwo(left, right);
    }

    ListNode* sortList(ListNode* head) { return helper(head); }
};