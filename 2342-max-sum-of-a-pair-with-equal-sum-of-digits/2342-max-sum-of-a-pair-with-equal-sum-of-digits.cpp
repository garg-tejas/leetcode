class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> numSum;
        sort(nums.begin(), nums.end());
        for (auto& num : nums) {
            int n = num;
            int sum = 0;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            numSum[sum].push_back(num);
        }
        int maxSum = -1;
        for (auto& it : numSum) {
            if (numSum[it.first].size() > 1) {
                int sum = 0;
                // sort(it.second.begin(), it.second.end());
                sum = it.second[it.second.size() - 1] +
                      it.second[it.second.size() - 2];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};