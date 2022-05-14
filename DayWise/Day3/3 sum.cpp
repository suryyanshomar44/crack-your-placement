class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if(nums.size()<3) {
            return ans;
        }
        for(int i=0; i<nums.size()-2; i++) {
            if(i!=0 && nums[i] == nums[i-1]) {
                continue;
            }
            int lo = i+1;
            int hi = nums.size()-1;
            while(lo<hi) {
                
                int s = nums[lo] + nums[hi];
                if(s+nums[i] < 0) 
                    lo++;
                else if(s+nums[i] > 0)
                    hi--;
                else{
                    vector<int> res;
                    res.push_back(nums[i]);
                    res.push_back(nums[lo]);
                    res.push_back(nums[hi]);
                    ans.push_back(res);
                    while(lo<hi && nums[lo]==nums[lo+1]) lo++;
                    while(lo<hi && nums[hi]==nums[hi-1]) hi--;
                    lo++;
                    hi--;
                }
            }
        }
        return ans;
    }
};
