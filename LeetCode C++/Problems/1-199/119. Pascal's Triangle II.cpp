class Solution {
public:

    vector<int> getRow(int rowIndex) {
        // initialization
        vector<int> triangle(rowIndex+1,1);

        // calculation
        for (int loop = 0;loop <= rowIndex;loop++) {
            for (int i = loop-1;i >= 1;i--) {
                triangle[i] += triangle[i-1];
            }
        }

        return triangle;
    }
};
