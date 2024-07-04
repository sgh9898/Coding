class Solution {
public:
    int countPoints(string rings) {
        vector<int> bit(10, 0);
        for (int i = 0; i < rings.size() - 1; i += 2) {
        	if (rings[i] == 'R') {
                bit[rings[i + 1] - '0'] |= 4;
            } else if (rings[i] == 'G') {
                bit[rings[i + 1] - '0'] |= 2;
            } else if (rings[i] == 'B') {
                bit[rings[i + 1] - '0'] |= 1;
            }
        }

        int cnt = 0;
        for (int i = 0; i < bit.size(); i++) {
            if (bit[i] == 7) {
                cnt++;
            }
        }
        return cnt;
    }
};