class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> C;
        int cum = 0;
        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            freq[B[i]]++;
            if (freq[A[i]] == 2 && freq[B[i]] == 2 && A[i] != B[i])
                cum += 2;
            else if (freq[A[i]] == 2 || freq[B[i]] == 2)
                cum++;
            C.push_back(cum);
        }
        return C;
    }
};