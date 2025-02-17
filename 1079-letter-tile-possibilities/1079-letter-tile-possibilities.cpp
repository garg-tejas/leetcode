class Solution {
public:
    int backtracking(vector<int>&charFreq){
        int res = 0;
        for(int i=0;i<26;i++){
            if(charFreq[i]>0){
                res++;
                charFreq[i]--;
                res+=backtracking(charFreq);
                charFreq[i]++;
            }
        }
        return res;
    }
    int numTilePossibilities(string tiles) {
        vector<int> charFreq(26, 0);
        for (char c : tiles) {
            charFreq[c - 'A']++;
        }
        return backtracking(charFreq);
    }
};