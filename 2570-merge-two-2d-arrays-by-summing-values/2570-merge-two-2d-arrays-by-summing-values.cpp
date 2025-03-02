class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        map<int, int> mp;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i < n; i++) {
            mp[nums1[i][0]] += nums1[i][1];
        }
        for (int i = 0; i < m; i++) {
            mp[nums2[i][0]] += nums2[i][1];
        }
        vector<vector<int>> result;
        for(auto ele : mp){
            result.push_back({ele.first, ele.second});
        }
        return result;
    }
};