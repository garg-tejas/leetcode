class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productFreq;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                productFreq[nums[i] * nums[j]]++;
            }
        }
        int res = 0;
        for (auto& itr : productFreq) {
            if (itr.second > 1) {
                res += (itr.second - 1)*(itr.second) * 4;
            }
        }
        return res;
    }
};