class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        int rotationIndex = left;
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int realMid = (mid + rotationIndex) % nums.size();
            if (nums[realMid] < target)
                left = mid + 1;
            else if (nums[realMid] > target)
                right = mid - 1;
            else
                return realMid;
        }
        return -1;
    }
};