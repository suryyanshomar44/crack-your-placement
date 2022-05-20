//https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for(int i=0; i<str.size(); i++) {
            char c = str[i];
            if(c=='(' || c=='{' || c=='[') {
                st.push(c);
            }
            else if(st.empty()) {
                return false;
            }
            else if(c == '}') {
                if(st.top() =='{') st.pop();
                else return false;
                
            }
            else if(c==')') {
                if(st.top() =='(') st.pop();
                else return false;
            }
            else if(c==']') {
                if(st.top() =='[') st.pop();
                else return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};
