class Solution {
public:
    bool doesAliceWin(string s) {
        int count=0;
        for(char c: s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        }
        return false;
    }
};