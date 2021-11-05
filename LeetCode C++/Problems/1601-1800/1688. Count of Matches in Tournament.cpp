class Solution {
public:
    int numberOfMatches(int n) {
        // int teams = n, matches = 0;
        // while (teams > 1) {
        //     matches += teams / 2;
        //     teams = (teams + 1) / 2;
        // }
        // return matches;
        return n - 1;   // one team is eliminated in one match
    }
};
