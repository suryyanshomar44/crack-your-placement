//https://leetcode.com/problems/majority-element/submissions/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == majority) {
                count++;
            }
            else if(count == 0) {
                majority = nums[i];
            }
            else {
                count--;
            }
        }
        return majority;
    }
};
