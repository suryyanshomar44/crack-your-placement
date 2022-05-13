class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int lo = 1;
        int i;
        for(i=1; i<nums.size(); i++) {
            if(nums[i] != prev) {
                nums[lo] = nums[i];
                lo++;
                prev = nums[i];
            }
        }
        return lo;
    }
};
