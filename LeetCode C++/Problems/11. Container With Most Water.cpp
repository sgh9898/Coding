class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2)      return 0;
        int lt = 0,rt = height.size()-1;
        int max_area = 0;

        while (lt != rt) {
            max_area = max(max_area,(rt-lt)*min(height[lt],height[rt]));
            if (height[lt] >= height[rt]) {
                rt--;
            } else {
                lt++;
            }
        }
        return max_area;
    }
};
