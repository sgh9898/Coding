class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> map;
        int sum = 0;
        for (int num : answers) {
            if (map.count(num) && map[num] > 0) {
                map[num]--;
            } else {
                map[num] = num;
                sum += num + 1;
            }
        }
        return sum;
    }
};
