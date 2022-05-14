class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums.size() < 4)
            return ans;
        for(int i=0; i<nums.size()-3; i++) {
            
            if(i!=0 && nums[i]==nums[i-1]) 
                    continue;
            if(nums[i]>0 && nums[i]>target) 
                break;
            int target1 = target-nums[i];
            for(int j=i+1; j<nums.size()-2; j++) {
                if((j-1)!=i && nums[j]==nums[j-1])
                    continue;
                int target2 = target1-nums[j];
                int lo = j+1;
                int hi = nums.size()-1;
                while(lo<hi) {
                    int s = nums[lo]+nums[hi];
                    
                    if(s<target2) {
                        lo++;
                    }
                    else if(s>target2) {
                        hi--;
                    }
                    else {
                        vector<int> res;
                        res.push_back(nums[i]);
                        res.push_back(nums[j]);
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
        }
        return ans;
   
    }
};
