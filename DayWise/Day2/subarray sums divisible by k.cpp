class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int s = 0;
        int ans = 0;
        int r = 0;
        mp[0] = 1;
        for(int i=0; i<nums.size(); i++) {
            s += nums[i];
            r = s%k;
            if(r<0) {
                r += k;
            }
            if(mp.find(r) != mp.end()) {
                ans += mp[r];
                mp[r]++;
            }
            else {
                mp[r] = 1;
            }
        }
        return ans;
    }
};
