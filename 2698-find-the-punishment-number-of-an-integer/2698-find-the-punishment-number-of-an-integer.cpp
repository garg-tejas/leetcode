class Solution {
public:
    int check(int num, int curSum, int target) {
        if (num == 0)
            return curSum == target;
        return check(num / 10, curSum + num % 10, target) ||
               check(num / 100, curSum + num % 100, target) ||
               check(num / 1000, curSum + num % 1000, target) ||
               check(num / 10000, curSum + num % 10000, target);
    }
    int punishmentNumber(int n) {
        int punish = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i*i;
            if (check(sq, 0, i)) {
                punish += sq;
            }
        }
        return punish;
    }
};