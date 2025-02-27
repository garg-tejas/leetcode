class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> numSet(arr.begin(), arr.end());
        int maxSub = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int cur = arr[i];
                int res = 2;
                int prev = arr[j];
                cur = cur + prev;
                while (numSet.find(cur) != numSet.end()) {
                    int temp = cur;
                    cur += prev;
                    prev = temp;
                    maxSub = max(maxSub, ++res);
                }
            }
        }
        return maxSub;
    }
};