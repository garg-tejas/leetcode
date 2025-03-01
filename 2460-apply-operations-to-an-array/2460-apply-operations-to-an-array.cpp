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
            if (nonZeroPointer < n && zeroPointer < n && zeroPointer < nonZeroPointer) {
                nums[zeroPointer] = nums[nonZeroPointer];
                nums[nonZeroPointer] = 0;
            }
            else if(zeroPointer > nonZeroPointer){
                nonZeroPointer = zeroPointer;
            }
        }
    }
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
                i++;
            }
        }
        moveZeroes(nums);
        return nums;
    }
};