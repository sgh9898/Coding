class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = -1;
        int lt = 0, rt = citations.size() - 1;
        int positive = 0;
        while (lt <= rt) {
            int mid = lt + (rt - lt) / 2;
            if ((citations.size() - mid) >= citations[mid]) {
                res = max(res, citations[mid]);
                lt = mid + 1;
            } else {
                if (citations[mid] > 0) {
                    res = max(res, (int) citations.size() - mid);
                }
                rt = mid - 1;
            }
        }
        return res;
    }
};