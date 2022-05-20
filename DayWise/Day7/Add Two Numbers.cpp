//https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode* head = &dummy;
        int carry = 0;
        while(l1 || l2) {
            int add = (l1!=NULL?l1->val:0) + (l2!=NULL?l2->val:0) + carry;
            int data = add%10;
            carry = add/10;
            head->next = new ListNode(data);
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            head = head->next;
        }
        if(carry!=0) {
            head->next = new ListNode(carry);
        } 
        return dummy.next;
        
    }
};
