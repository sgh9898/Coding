class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int num : nums1) {
            map[num]++;
        }
        for (int num : nums2) {
            if (map.count(num)) {
                res.push_back(num);
                map[num]--;
                if (map[num] == 0) {
                    map.erase(num);
                }
            }
        }
        return res;
    }

    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_map<int, int> map;
    //     vector<int> res;
    //     for (int num : nums1) {
    //         map[num]++;
    //     }
    //     for (int num : nums2) {
    //         if (map[num]-- > 0) {
    //             res.push_back(num);
    //         }
    //     }
    //     return res;
    // }
};
