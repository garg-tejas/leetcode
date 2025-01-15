class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        string s;
        int idx1 = 0, idx2 = 0;
        for (int i = 0; i < max(l1, l2); i++) {
            if (idx1 < l1)
                s += word1[idx1++];
            if (idx2 < l2)
                s += word2[idx2++];
        }
        return s;
    }
};