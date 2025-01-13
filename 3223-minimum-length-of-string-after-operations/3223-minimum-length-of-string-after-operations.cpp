class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        int n = s.length();
        for (char c : s) {
            freq[c - 'a']++;
            if (freq[c - 'a'] == 3) {
                freq[c - 'a'] = 1;
                n -= 2;
            }
        }
        return n;
    }
};