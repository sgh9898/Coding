class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;  // val, cnt
        for (size_t i = 0; i < arr1.size(); i++) {
            mp[arr[i]]++;
        }
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            cout<<iter->first<<" "<<iter->second<<endl;
        }
        vector<int> res;
        // elements in arr2
        for (size_t i = 0; i < arr2.size(); i++) {
            auto iter = mp.find(arr2[i]);
            if (iter != mp.end()) {
                while (iter->second != 0) {
                    res.push_back(iter->first);
                    iter->second--;
                }
                mp.erase(iter);
            }
        }

        // rest elements
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            while (iter->second != 0) {
                res.push_back(iter->first);
                iter->second--;
            }
        }
        return res;
    }
};
