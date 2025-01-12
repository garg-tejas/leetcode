class Solution {
public:
    bool checkValidString(string s) {
        int open=0;
        for(char c: s){
            if(c!=')') open++;
            else open--;
            if(open<0) return false;
        }
        int close=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!='(') close++;
            else close--;
            if(close<0) return false;
        }
        return true;
    }
};