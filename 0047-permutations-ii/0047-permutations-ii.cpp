class Solution {
public:
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 720 * 7, 720 * 7 * 8};
    void next_perm(vector<int>& nums) {
        int n = nums.size();
        int left = n - 2;
        while (left >= 0 && nums[left] >= nums[left + 1]) {
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        permutations.push_back(nums);
        int n = nums.size();
        int den = 1;
        unordered_map<int,int>freq;
        for(auto&num:nums){
            freq[num]++;
            den*=freq[num];
        }
        
        for (int i = 1; i < fact[n]/den; i++) {
            next_perm(nums);
            permutations.push_back(nums);
        }
        return permutations;
    }
};