//https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode* head) {
        string s = "";
        ListNode* temp = head;
        while(temp!=NULL) {
            s += (temp->val + '0');
            temp = temp->next;
        }
        int res = 0;
        int t = 1;
        for(int i=s.size()-1; i>=0; i--) {
            int a = s[i]-'0';
            res += (a*t);
             t = t*2;
            
        }
        return res;      
    }
};
