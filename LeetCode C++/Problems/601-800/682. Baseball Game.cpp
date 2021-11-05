class Solution {
public:
    int calPoints(vector<string>& ops) {
        int index = 0;
        vector<int> stack;
        for (auto c : ops) {
            if (c == "C") {
                stack.pop_back();
                index--;
            }
            else {
                int tmp;
                if (c == "+") {
                    tmp = stack[index - 1] + stack[index - 2];
                } else if (c == "D") {
                    tmp = stack[index - 1] * 2;
                } else {
                    tmp = stoi(c);
                }
                stack.push_back(tmp);
                index++;
            }
        }
        return accumulate(stack.begin(),stack.end(),0);
    }
};
