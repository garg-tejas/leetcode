class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = 1, width = 1;
        int maxVolume = 0;
        int n = height.size();
        for (int i = 0; i < n - 1; i++) {
            if (left <= height[i]) {
                left = height[i];
                for (int j = i + 1; j < n; j++) {
                    width = j - i;
                    int volume = min(left, height[j]) * width;
                    maxVolume=max(volume,maxVolume);
                }
            }
        }
        return maxVolume;
    }
};