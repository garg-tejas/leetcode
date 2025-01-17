class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorSum = 0;
        for (auto i : derived) {
            xorSum ^= i;
        }
        if (xorSum)
            return false;
        return true;
    }
};