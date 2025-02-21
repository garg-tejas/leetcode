class Solution {
public:
    void next_perm(vector<int>& nums) {
        int n = nums.size();
        int left = n - 2;
        while (left >= 0 && nums[left] > nums[left + 1]) {
            left--;
        }
        if (left >= 0) {
            int right = n - 1;
            while (right >= 0 && nums[left] >= nums[right]) {
                right--;
            }
            swap(nums[left], nums[right]);
        }
        reverse(nums.begin() + left + 1, nums.end());
    }
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720};
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        int n = nums.size();
        permutations.push_back(nums);
        for (int i = 1; i < fact[n]; i++) {
            next_perm(nums);
            permutations.push_back(nums);
        }
        return permutations;
    }
};