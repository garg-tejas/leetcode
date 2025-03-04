class Solution {
public:
    vector<int> powers;
    void populate(int n) {
        int pow = 1;
        powers.push_back(pow);
        while (pow * 3 <= n) {
            pow *= 3;
            powers.push_back(pow);
        }
    }
    bool checkPowersOfThree(int n) {
        populate(n);
        return recurCheck(n);
    }
    int bs(int target) {
        int left = 0;
        int right = powers.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target > powers[mid])
                left = mid + 1;
            else if (target < powers[mid])
                right = mid - 1;
            else
                return mid;
        }
        return right;
    }
    bool recurCheck(int n) {
        if (n == 0)
            return true;
        if (n < 0)
            return false;
        int powIndex = bs(n);
        if (powIndex < 0)
            return false;
        int power = powers[powIndex];
        powers.erase(powers.begin() + powIndex);
        return recurCheck(n - power);
    }
};