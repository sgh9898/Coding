class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int zeros = 0, temp = 0;
        for (int num : seats) {
            if (num == 1) {
                zeros = max(zeros, temp);
                temp = 0;
            } else {
                temp++;
            }
        }
        zeros = zeros/2 + 1;

        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) {
                zeros = max(zeros, i);
                break;
            }
        }

        for (int i = seats.size() - 1; i >= 0; i--) {
            if (seats[i] == 1) {
                zeros = max(zeros, seats.size() - 1 - i);
                break;
            }
        }

        return zeros;
    }
};
