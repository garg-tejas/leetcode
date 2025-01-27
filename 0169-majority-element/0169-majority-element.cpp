class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int maxFreq = 0;
        int max = -1;
        for (auto& num : nums) {
            freq[num]++;
            if (freq[num] > maxFreq) {
                max = num;
                maxFreq = freq[num];
                // cout<<max<<" "<<freq[num]<<endl;
            }
        }
        return max;
    }
};