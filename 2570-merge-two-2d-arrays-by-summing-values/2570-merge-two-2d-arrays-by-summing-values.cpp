class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        map<int, int> mp;
        int n = nums1.size();
        int m = nums2.size();
        for (auto num : nums1) {
            mp[num[0]] += num[1];
        }
        for (auto num : nums2) {
            mp[num[0]] += num[1];
        }
        vector<vector<int>> result;
        for (auto ele : mp) {
            result.push_back({ele.first, ele.second});
        }
        return result;
    }
};