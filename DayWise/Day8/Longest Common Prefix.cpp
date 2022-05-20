//https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        if(strs.size() == 0) {
            return "";
        }
        
        string a = strs[0];
        string b = strs[strs.size()-1];
        string ans = "";
        for(int i=0; i<a.size(); i++) {
            if(a[i]!=b[i]) 
                break;
            ans += a[i];
        }
        return ans;
    }
};
