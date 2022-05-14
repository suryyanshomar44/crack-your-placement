//https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int minr = 0;
        int minc = 0;
        int maxr = m-1;
        int maxc = n-1;
        int c = 0;
        int total = m*n;
        int i=0, j=0;
        while(c<total) {
           for(i=minr, j=minc; j<=maxc && c<total; j++) {
               ans.push_back(matrix[i][j]);
               c++;
            }
            minr++;
            for(j=maxc, i=minr; i<=maxr && c<total; i++) {
               ans.push_back(matrix[i][j]);
               c++;
            }
            maxc--;
            for(i=maxr, j=maxc; j>=minc && c<total; j--) {
               ans.push_back(matrix[i][j]);
               c++;
            }
            maxr--;
            for(j=minc, i=maxr; i>=minr && c<total; i--) {
               ans.push_back(matrix[i][j]);
               c++;
            }
            minc++;
        }
        return ans;
    }
};

