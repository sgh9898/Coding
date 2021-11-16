class Solution {
public:
    int get(vector<int>& h){
        int s[210], top = -1;
        vector<int> l(h.size()), r(h.size());

        for(int i = 0; i < h.size(); ++i){
            if(top == -1){
                l[i] = -1;
            }else{
                while(top > -1 && h[s[top]] > h[i]) r[s[top--]] = i;
            }
            if(top == -1) l[i] = -1;
            else if(h[s[top]] == h[i]) l[i] = l[s[top]];
            else l[i] = s[top];
            s[++top] = i;
        }

        while(top > -1) r[s[top--]] = h.size();
        int res = 0;
        for(int i = 0; i<h.size(); ++i){
            res = max(res, h[i]*(r[i]-l[i]-1));
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return 0;

        int res = 0;

        vector<int> h(matrix[0].size(), 0);

        for(int i = 0; i<matrix.size(); ++i){
            for(int j = 0; j<matrix[0].size(); ++j){
                if(matrix[i][j] == '0') h[j] = 0;
                else ++h[j];
            }
            res = max(get(h), res);
        }

        return res;
    }
};
