class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> unique;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[n - 1] == 0 && nums[0] == 0 && n > 2)
            return {{0, 0, 0}};
        for (int idx = 0; idx < n; idx++) {
            int i = idx + 1, j = nums.size() - 1;
            int target = -nums[idx];
            while (i < j) {
                int curr = nums[i] + nums[j];
                if (curr == target && i != j && j != idx && idx != i) {
                    vector<int> temp;
                    temp.push_back(nums[idx]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    unique.insert(temp);
                    i++;
                    j--;
                } else if (curr < target)
                    i++;
                else
                    j--;
            }
        }
        vector<vector<int>> res(unique.begin(), unique.end());
        return res;
    }
};