class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i, j = 0;
        char temp = '';
        for (i = 0; i < typed.size(); i++) {
            if (j >= name.size())   return false;
            if (typed[i] == name[j]) {
                temp = name[j];
                j++;
                continue;
            } else if (typed[i] == temp) {
                continue;
            } else {
                return false;
            }
        }

        while (i < typed.size()) {
            if (typed[i] != temp)   return false;
            i++;
        }
        return true;
    }
};
