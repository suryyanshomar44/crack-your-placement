//https://leetcode.com/problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        if(n==1)
            return 1;
        int dp[n+1];
        for(int i=0; i<=n; i++)
            dp[i] = 0;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        
        for(int i=3; i<=n; i++) {
            int l = 0;
            while(l<i) {
                dp[i] += (dp[l]*dp[i-l-1]);
                l++;
            }
        }
        return dp[n];
        
    }
};
