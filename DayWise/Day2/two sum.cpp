class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;
        vector<int> v;
        for(int i=0; i<nums.size(); i++) {
            int ntofind = target-nums[i];
            if(mp.find(ntofind) != mp.end()) {
                v.push_back(mp[ntofind]);
                v.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return v;
    }
};
