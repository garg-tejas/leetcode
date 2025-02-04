class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maximum = nums[0], incSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            incSum = nums[i - 1] < nums[i] ? incSum + nums[i] : nums[i];
            maximum = max(maximum, incSum);
        }
        return maximum;
    }
};