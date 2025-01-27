class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPointer = 0, nonZeroPointer = 0;
        int n = nums.size();
        while (zeroPointer < n && nonZeroPointer < n) {
            while (zeroPointer < n && nums[zeroPointer])
                zeroPointer++;
            while (nonZeroPointer < n && nums[nonZeroPointer] == 0)
                nonZeroPointer++;
            if (nonZeroPointer < n && zeroPointer < n) {
                nums[zeroPointer] = nums[nonZeroPointer];
                nums[nonZeroPointer] = 0;
            }
        }
    }
};