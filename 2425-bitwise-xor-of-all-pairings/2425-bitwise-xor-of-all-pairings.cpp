class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        if(nums2.size()%2){
            for(auto &num1:nums1){
                res=res^num1;
            }
        }
        if(nums1.size()%2){
            for(auto &num2:nums2){
                res=res^num2;
            }
        }
        return res;
    }
};