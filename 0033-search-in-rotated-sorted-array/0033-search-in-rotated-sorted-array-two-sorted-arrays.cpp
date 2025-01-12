class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int comparator;
            if((nums[mid]>=nums[0] && target>=nums[0]) || (nums[mid]<nums[0] && target<nums[0])){
                comparator=nums[mid];
            }
            else{
                if(target<nums[0]){
                    comparator=INT_MIN;
                }
                else{
                    comparator=INT_MAX;
                }
            }
            if(comparator<target) left=mid+1;
            else if(comparator>target) right=mid-1;
            else return mid;
        }
        return -1;
    }
};