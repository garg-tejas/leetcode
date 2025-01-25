class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> sorted = nums;
        int n = nums.size();
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> numToGroup;
        int groupNum = 0;
        unordered_map<int, queue<int>> groupToNums;
        numToGroup[sorted[0]] = groupNum;
        groupToNums[groupNum].push(sorted[0]);
        for (int i = 1; i < n; i++) {
            if (sorted[i] - sorted[i - 1] > limit)
                groupNum++;
            numToGroup[sorted[i]] = groupNum;
            groupToNums[groupNum].push(sorted[i]);
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            res.push_back(groupToNums[numToGroup[nums[i]]].front());
            groupToNums[numToGroup[nums[i]]].pop();
        }
        return res;
    }
};