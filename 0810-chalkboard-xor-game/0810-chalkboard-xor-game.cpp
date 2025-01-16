class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int res=0;
        for(auto num:nums)
            res^=num;
        if(res==0 || nums.size()%2==0) return true;
        return false;
    }
};