class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> smash;
        for (int stone : stones) {
            smash.push(stone);
        }
        while (smash.size() > 1) {
            int heaviest = smash.top();
            smash.pop();
            int second_h = smash.top();
            smash.pop();
            if (heaviest - second_h > 0) {
                smash.push(heaviest - second_h);
            }
        }
        return smash.empty() ? 0 : smash.top();
    }
};
