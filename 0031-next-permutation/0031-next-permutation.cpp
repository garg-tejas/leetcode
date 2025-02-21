class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int left = n - 2;
        while (left >= 0 && nums[left] >= nums[left + 1]) {
            left--;
        }

        if (left >= 0) {
            int right = n - 1;
            while (nums[right] <= nums[left]) {
                right--;
            }
            swap(nums[left], nums[right]); 
        }
        reverse(nums.begin() + left + 1, nums.end());
    }
};