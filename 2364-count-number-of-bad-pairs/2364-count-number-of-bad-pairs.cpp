class Solution {
public:
    long long pairCalculator(long long n) { return n * (n - 1) / 2; }

    long long countBadPairs(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] -= i;
        }
        long long badPair = pairCalculator(nums.size());
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++) {
            ump[nums[i]]++;
        }
        for (auto& num : nums) {
            badPair -= pairCalculator(ump[num]);
            ump[num] = 0;
        }
        return badPair;
    }
};