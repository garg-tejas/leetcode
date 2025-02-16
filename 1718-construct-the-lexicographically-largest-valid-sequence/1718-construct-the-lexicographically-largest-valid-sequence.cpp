class Solution {
public:
    bool backtracking(vector<int>& res, unordered_set<int>& used, int idx,
                      int n) {
        if (idx == res.size())
            return true;

        if (res[idx] != 0)
            return backtracking(res, used, idx + 1, n);

        for (int num = n; num >= 1; --num) {
            if (used.count(num))
                continue;
            if (num > 1 && (idx + num >= res.size() || res[idx + num] != 0))
                continue;

            used.insert(num);
            res[idx] = num;
            if (num > 1)
                res[idx + num] = num;

            if (backtracking(res, used, idx + 1, n))
                return true;

            used.erase(num);
            res[idx] = 0;
            if (num > 1)
                res[idx + num] = 0;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> res(size, 0);
        unordered_set<int> used;
        backtracking(res, used, 0, n);
        return res;
    }
};