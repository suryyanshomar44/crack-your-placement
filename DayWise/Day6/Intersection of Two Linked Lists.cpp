//https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head) {
        int len = 0;
        while(head!=NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = length(headA);
        int lb = length(headB);
        ListNode* tempa = headA;
        ListNode* tempb = headB;
  
        while(la>lb) {
            tempa = tempa->next;
            la--;
        }

         while(la<lb) {
            tempb = tempb->next;
            lb--;
        }
        
        while(tempa!=NULL) {
            if(tempa==tempb) {
                return tempa;
            }
            tempa=tempa->next;
            tempb = tempb->next;
        }
        return NULL;
        
    }
};
