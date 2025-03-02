class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int idx1 = 0, idx2 = 0;
        vector<vector<int>> mergedArray;
        while (idx1 < n && idx2 < m) {
            if (nums1[idx1][0] == nums2[idx2][0]) {
                mergedArray.push_back(
                    {nums1[idx1][0], nums1[idx1][1] + nums2[idx2][1]});
                idx1++;
                idx2++;
            } else if (nums1[idx1][0] < nums2[idx2][0]) {
                mergedArray.push_back({nums1[idx1][0], nums1[idx1][1]});
                idx1++;
            } else {
                mergedArray.push_back({nums2[idx2][0], nums2[idx2][1]});
                idx2++;
            }
        }
        while (idx1 < n) {
            mergedArray.push_back({nums1[idx1][0], nums1[idx1][1]});
            idx1++;
        }
        while (idx2 < m) {
            mergedArray.push_back({nums2[idx2][0], nums2[idx2][1]});
            idx2++;
        }
        return mergedArray;
    }
};