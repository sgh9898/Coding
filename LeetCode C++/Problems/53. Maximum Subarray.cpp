class Solution {
public:
    vector<int> FindCrossing(vector<int>& vec, int low, int mid, int high) {
        int lt_sum = INT_MIN;
        // max_lt == max_rt == mid because the subarray expands from the midpoint
        int sum = 0, max_lt = mid, max_rt = mid;
        for (int i = mid; i >= low; i--) {
            sum += vec[i];
            // make profit
            if (sum > lt_sum) {
                lt_sum = sum;
                max_lt = i;
            }
        }

        int rt_sum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= high; i++) {
            sum += vec[i];
            if (sum > rt_sum) {
                rt_sum = sum;
                max_rt = i;
            }
        }
        return {max_lt, max_rt, lt_sum + rt_sum};
    }

    vector<int> Subarray(vector<int>& vec, int low, int high) {
        if (low == high) {
            return {low, high, vec[low]};
        } else {
            int mid = (low + high) / 2;
            vector<int> vec_lt = Subarray(vec, low, mid);
            vector<int> vec_rt = Subarray(vec, mid + 1, high);
            vector<int> vec_xing = FindCrossing(vec, low, mid, high);

            if (vec_lt.back() >= vec_rt.back() && vec_lt.back() >= vec_xing.back()) {
                return {vec_lt[0], vec_lt[1], vec_lt[2]};
            } else if (vec_rt.back() >= vec_lt.back() && vec_rt.back() >= vec_xing.back()) {
                return {vec_rt[0], vec_rt[1], vec_rt[2]};
            } else {
                return {vec_xing[0], vec_xing[1], vec_xing[2]};
            }
        }
    }

    int maxSubArray(vector<int>& nums) {
        return Subarray(nums, 0, nums.size() - 1);
    }
};
