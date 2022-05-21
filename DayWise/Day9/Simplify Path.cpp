//https://leetcode.com/problems/simplify-path/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans = "";
        int i=0;
        vector<string> v;
        string temp = "";
        for(int i=0; i<path.size(); i++) {
            if(path[i]!='/') {
                temp += path[i];
            }
            else {
                v.push_back(temp);
                temp="";
            }
        }
        v.push_back(temp);
        
        for(int i=0; i<v.size(); i++) {
            if(!st.empty() && v[i]=="..") st.pop();
            else if(v[i]!="." && v[i]!="" && v[i]!="..") st.push(v[i]);
        }
        if(st.empty()) return "/";
        while(!st.empty()) {
            ans.insert(0, "/"+st.top());
            st.pop();
        }
        
        return ans;
        
    }
};
