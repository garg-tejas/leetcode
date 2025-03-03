class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> left;
        vector<int> right;
        int pCount = 0;
        for (auto& num : nums) {
            if (num < pivot) {
                left.push_back(num);
            } else if (num > pivot) {
                right.push_back(num);
            } else {
                pCount++;
            }
        }
        int idx = 0;
        for (auto& num : left) {
            nums[idx] = num;
            idx++;
        }
        while (pCount--) {
            nums[idx] = pivot;
            idx++;
        }
        for (auto& num : right) {
            nums[idx] = num;
            idx++;
        }
        return nums;
    }
};