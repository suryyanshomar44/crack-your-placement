//https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s, 0, n-1);
        int i=0;
        while(i<n) {
            if(s[i] == ' ') {
                i++;
                continue;
            }
            int j=i;
            string word = "";
            while(i<n && s[i]!=' ') {
                word += s[i];
                i++;
            }
            reverse(s, j, i-1);
        }
        cout<<s<<endl;
        string ans = clearSpace(s);
        return ans;
    }
    void reverse(string &s, int i, int j) {
        while(i<j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
    }
    string clearSpace(string &s) {
       string nstr = "";
        int i=0;
        int j=s.size();
        while(i<j && s[i]==' ') i++;
        while(i<j) {
            while(s[i]==' ' && s[i+1] == ' ') i++;
            if(i==j-1 && s[i]==' '){
                i++;
                continue;
            }
            nstr += s[i++];
        }
        return nstr;
    }
};
