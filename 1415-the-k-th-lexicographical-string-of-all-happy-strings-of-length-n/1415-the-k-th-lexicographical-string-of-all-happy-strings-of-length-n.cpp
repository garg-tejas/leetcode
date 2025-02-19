class Solution {
public:
    string getHappyString(int n, int k) {
        string res(n, 'a');
        if (k > 3 * pow(2, n - 1))
            return "";
        int p = pow(2, n - 1);
        int startLetter = (k - 1) / p;
        k = k - 1 - (startLetter * p);
        if (startLetter == 0)
            res[0] = 'a';
        else if (startLetter == 1)
            res[0] = 'b';
        else
            res[0] = 'c';
        unordered_map<char, vector<char>> dict;
        dict['a'] = {'b', 'c'};
        dict['b'] = {'a', 'c'};
        dict['c'] = {'a', 'b'};
        for (int i = 1; i < n; i++) {
            p /= 2;
            int idx = k < p ? 0 : 1;
            if (idx == 1)
                k -= p;
            cout << idx << " " << k << " " << p << endl;
            res[i] = dict[res[i-1]][idx];
        }
        return res;
    }
};