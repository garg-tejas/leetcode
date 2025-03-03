class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result (nums.size());
        int less = 0, equal = 0;
        for(auto&num:nums){
            if(num<pivot) less++;
            else if(num==pivot) equal++;
        }
        int lidx = 0, eidx = less, gidx = less+equal;
        for(auto&num:nums){
            if(num<pivot){
                result[lidx] = num;
                lidx++;
            }
            else if(num>pivot){
                result[gidx] = num;
                gidx++;
            }
            else{
                result[eidx] = num;
                eidx++;
            }
        }
        return result;
    }
};