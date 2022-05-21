//https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, "", n, 0, 0);
        return ans;
    }
    void generate(vector<string> &v, string str, int total, int open, int close) {
        if(open==total && close==total) {
            v.push_back(str);
            return;
        }
        if(open<total) generate(v, str+"(", total, open+1, close);
        if(close<open) generate(v, str+")", total, open, close+1);
    }
};
