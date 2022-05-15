//https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> res;
        while(i<m && j<n) {
            if(nums1[i] <= nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            }
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        if(i==m) {
            while(j<n) {
                res.push_back(nums2[j]);
                j++;
            } 
        }
        else if(j==n) {
            while(i<m) {
                res.push_back(nums1[i]);
                i++;
            }
        }
        for(int i=0; i<res.size(); i++) {
            nums1[i] = res[i];
        }
    }
};
