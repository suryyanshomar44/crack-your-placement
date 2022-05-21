//https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mps;
        unordered_map<char, int> mpt;
        for(int i=0; i<t.size(); i++) {
            mpt[t[i]]++;
            //cout<<mpt[t[i]]<<endl;
        }
        string ans = "";
        int sl = s.size();
        int mct = 0; 
        int dmct = t.length();
        int i=-1;
        int j=-1;
        //acquire
        while(true) {
            bool f1 = false;
            bool f2 = false;
            while(i<sl-1 && mct<dmct) {

                i++;
                mps[s[i]]++;
                
                if(mps[s[i]] <= (mpt.find(s[i])!=mpt.end()?mpt[s[i]]:0))
                    mct++;
                f1 = true;
            }
            while(j<i && mct==dmct) {
                string pans = "";
                pans = s.substr(j+1, i-j);
                if(ans.size()==0 || pans.size()<ans.size()) 
                    ans = pans;
                j++;
                if(mps[s[j]]==1)
                    mps.erase(s[j]);
                else 
                    mps[s[j]]--;
                if((mps.find(s[j])!=mps.end()?mps[s[j]]:0) < (mpt.find(s[j])!=mpt.end()?mpt[s[j]]:0))
                 {   
                    mct--;
                }
                f2 = true;
            }
            if(f1==false && f2==false)
                break;
            
        }
        return ans;
    }
};
