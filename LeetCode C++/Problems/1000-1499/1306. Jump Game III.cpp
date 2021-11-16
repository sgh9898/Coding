class Solution {
public:
    bool Helper(vector<int>& arr, int idx, vector<bool>& visited) {
        // out of bounds
        if (idx < 0 || idx >= arr.size())  return false;
        // found
        if (arr[idx] == false)  return true;
        // visited
        if (visited[idx] == true) {
            return false;
        } else {
            visited[idx] = true;
            return Helper(arr, idx - arr[idx], visited) || Helper(arr, idx + arr[idx], visited);
        }
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), 0);
        return Helper(arr, start, visited);
    }
};
