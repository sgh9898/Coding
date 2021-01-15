class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int fwd = 0, bwd = people.size() - 1, cnt = 0;
        while (fwd <= bwd) {
            if (people[fwd] + people[bwd] <= limit) {
                fwd++;
            }
            cnt++;
            bwd--;
        }
        return cnt;
    }
};
