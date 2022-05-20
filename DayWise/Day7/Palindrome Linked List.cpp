//https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* rev = reverse(slow);
       // cout<<rev->val;
        fast = head;
        while(rev!=NULL) {
            if(fast->val != rev->val) {
                return false;
            }
            fast = fast->next;
            rev = rev->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* &slow) {
        ListNode* prev = NULL;
        while(slow != NULL) {
            ListNode* n = slow->next;
            slow->next = prev;
            prev = slow;
            slow = n;
        } 
        return prev;
    }
    
};
