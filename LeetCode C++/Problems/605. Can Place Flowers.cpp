class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (size_t i = 0; i < flowerbed.size(); i++) {
            // the neighbor of 1 must be 0
            if (flowerbed[i] == 1) {
                i++;
            } else if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
                n--;
                i++;
            }
            if (n <= 0) {
                return true;
            }
        }
        return false;
    }
};
