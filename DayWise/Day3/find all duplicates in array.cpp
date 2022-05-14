class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            int a = nums[i];
            if(a<0)
                a = -a;
            a = a-1;
            if(nums[a] < 0) {
                ans.push_back(a+1);
            }
            else {
                nums[a] = -nums[a];
            }
        }
        return ans;
    }
};
