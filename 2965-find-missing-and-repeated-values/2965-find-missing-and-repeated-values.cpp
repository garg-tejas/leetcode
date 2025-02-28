class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> freq;
        vector<int> res;
        int total=0;
        for (auto& g : grid) {
            for (auto& element : g) {
                freq[element]++;
                total += element;
                if (freq[element] == 2) {
                    res.push_back(element);
                }
            }
        }
        int n = grid.size();
        int second = ((n * n + 1) * n * n / 2) - total + res[0];
        res.push_back(second);
        return res;
    }
};