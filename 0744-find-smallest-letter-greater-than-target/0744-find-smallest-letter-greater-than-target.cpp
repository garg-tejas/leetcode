class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target < letters[mid])
                right = mid - 1;
            else if (target > letters[mid])
                left = mid + 1;
            else{
                left=mid+1;
            }

        }
        if (left < letters.size())
            return letters[left];
        return letters[0];
    }
};