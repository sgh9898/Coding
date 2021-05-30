class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> src;
        src.push_back(first);
        for (int i = 0; i < encoded.size(); i++) {
            src.push_back(encoded[i] ^ src[i]);
        }
        return src;
    }
};
