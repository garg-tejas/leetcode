class Solution {
public:
    int n;
    int binaryNum(string& num) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] == '1') {
                res += pow(2, n - 1 - i);
            }
        }
        return res;
    }

    string binary(int num) {
        string res(n, '0');
        if (num == 0) {
            return res;
        }
        int i = 0;
        while (num > 0) {
            res[i++] = (num % 2) + '0';
            num /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        n = nums[0].length();
        sort(nums.begin(), nums.end());
        vector<int> binToNum(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            binToNum[i] = binaryNum(nums[i]);
            if (binToNum[i] != i) {
                return binary(i);
            }
        }
        if (nums.size() < pow(2, n) - 1) {
            return binary(pow(2, n) - 1);
        }
        return "1";
    }
};