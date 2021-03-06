//https://leetcode.com/problems/reverse-linked-list-ii/

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
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        if(!head || left==right) {
            return head;
        }
        for(int i=0; i<left-1; i++) {
            pre = pre->next;
        }
        ListNode* curr = pre->next;
        for(int i=0; i<right-left; i++) {
            ListNode* temp = pre->next;
            pre->next = curr->next;
            curr->next = curr->next->next;
            pre->next->next = temp;
        }
        return dummy.next;
    }
};
