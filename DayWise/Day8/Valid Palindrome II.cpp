//https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool isPallin(string &s, int lo, int hi) {
        while(lo<hi) {
            if(s[lo]!=s[hi])
                return false;
            lo++;
            hi--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int lo = 0;
        int hi = s.size()-1;
        while(lo<hi) {
            if(s[lo] != s[hi]) {
                return isPallin(s, lo+1, hi) || isPallin(s,lo, hi-1);
            }
            lo++;
            hi--;
        }
        return true;
    }
};
