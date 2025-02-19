class Solution {
public:
    string getHappyString(int n, int k) {
        string res;
        if (k > 3 * pow(2, n - 1))
            return "";
        if (n == 1) {
            if (k == 1)
                return "a";
            else if (k == 2)
                return "b";
            return "c";
        }
        int p = pow(2, n - 1);
        int startLetter = (k - 1) / p;
        k = k - 1 - (startLetter * p);
        if (startLetter == 0)
            res += 'a';
        else if (startLetter == 1)
            res += 'b';
        else
            res += 'c';
        unordered_map<char, vector<char>> dict;
        dict['a'] = {'b', 'c'};
        dict['b'] = {'a', 'c'};
        dict['c'] = {'a', 'b'};
        for (int i = 2; i <= n; i++) {
            p /= 2;
            int idx = k < p ? 0 : 1;
            if (idx == 1)
                k -= p;
            cout << idx << " " << k << " " << p << endl;
            res += dict[res.back()][idx];
        }
        return res;
    }
};