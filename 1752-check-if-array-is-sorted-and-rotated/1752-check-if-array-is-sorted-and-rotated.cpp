class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        int flag = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                flag--;
                if (i + 1 < n) {
                    if (nums[i - 1] < nums[i + 1]) {
                        return false;
                    }
                }
            }
        }
        if (nums[n - 1] > nums[0])
            flag--;
        if (flag < -1) {
            return false;
        }
        return true;
    }
};