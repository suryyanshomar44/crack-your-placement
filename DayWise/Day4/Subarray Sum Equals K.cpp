//https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix[n];
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            prefix[i] = sum;
        }
        unordered_map<int, int> mp;
        mp[0]= 1;
        int ans = 0;
        for(int i=0; i<n; i++) {
            int diff = prefix[i]-k;
            if(mp.find(diff)!=mp.end()) {
                ans += mp[diff];
            }
            if(mp.find(prefix[i])!=mp.end()) 
                mp[prefix[i]]++;
            else
                mp[prefix[i]] = 1;
        }
        return ans;
    }
};
