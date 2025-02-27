class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> numSet(arr.begin(), arr.end());
        int maxSub = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int curr = arr[i];
                int res = 2;
                int prev = arr[j];
                curr = curr + prev;
                while (numSet.count(curr)) {
                    curr = curr + prev;
                    prev = curr - prev;
                    maxSub = max(maxSub, ++res);
                }
            }
        }
        return maxSub;
    }
};