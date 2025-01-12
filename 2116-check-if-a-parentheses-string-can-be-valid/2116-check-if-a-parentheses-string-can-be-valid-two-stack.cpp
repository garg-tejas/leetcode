class Solution {
public:
    bool canBeValid(string s, string lock) {
        stack<int> locked;
        stack<int> unlocked;
        int n=s.length();
        if(n%2) return false;
        for(int i=0;i<n;i++){
            if(lock[i]=='1' && s[i]=='(') locked.push(i);
            else if(lock[i]=='0') unlocked.push(i);
            else{
                if(!locked.empty()) locked.pop();
                else if(!unlocked.empty()) unlocked.pop();
                else return false;
            }
        }
        while(!locked.empty() && !unlocked.empty() && locked.top()<unlocked.top()){
            locked.pop();
            unlocked.pop();
        }
        return locked.empty();
    }
};