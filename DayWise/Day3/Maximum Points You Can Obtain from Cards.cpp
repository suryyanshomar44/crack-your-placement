class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int tsum = 0;
        int res = 0;
        int n = cardPoints.size();
        int m = n-k;
        if(n<k) {
            return 0;
        }
        for(int i=0; i<n; i++) {
            tsum += cardPoints[i];
        }
        for(int i=0; i<m; i++) {
            res += cardPoints[i];
        }
        int minsum = res;
        for(int i=m; i<n; i++) {
            res += cardPoints[i]-cardPoints[i-m];
            minsum = min(res, minsum);
        }
        return tsum-minsum;
    }
};
