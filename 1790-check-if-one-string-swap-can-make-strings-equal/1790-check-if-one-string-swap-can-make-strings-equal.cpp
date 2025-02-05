class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.length() != s2.length()) {
            cout << "lenght not equal";
            return false;
        }
        int notEqual = 0;
        unordered_map<char, int> s1Freq;
        unordered_map<char, int> s2Freq;
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            s1Freq[s1[i]]++;
            s2Freq[s2[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (s1Freq[s1[i]] != s2Freq[s1[i]]) {
                cout << "freq not equal " << s1[i] << " " << s2[i];
                return false;
            }
            
        }
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i])
                notEqual++;
            if (notEqual > 2) {
                cout << "not equal > 2";
                return false;
            }
        }
        if (notEqual % 2 == 0)
            return true;
        cout << "not equal = 1";
        return false;
    }
};