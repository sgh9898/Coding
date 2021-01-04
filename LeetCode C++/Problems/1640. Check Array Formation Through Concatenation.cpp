class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> dic;
        for (int i = 0; i < pieces.size(); i++) {
            dic[pieces[i][0]] = i;
        }

        for (int i = 0; i < arr.size();) {
            if (dic.find(arr[i]) == dic.end()) return false;
            auto& p = pieces[dic[arr[i]]];
            for (int j = 0; j < p.size(); j++, i++) {
                if (arr[i] != p[j]) return false;
            }
        }
        return true;
    }
};
