class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    	int h_max = 0, w_max = 0;
    	int h_curr = 0, w_curr = 0;
    	long mod = 1e9 + 7;
    	sort(horizontalCuts.begin(), horizontalCuts.end());
    	sort(verticalCuts.begin(), verticalCuts.end());
    	for (int i = 0; i < horizontalCuts.size(); i++) {
    		h_max = max(horizontalCuts[i] - h_curr, h_max);
            h_curr = horizontalCuts[i];
    	}
        h_max = max(horizontalCuts[horizontalCuts.size() - 1] - h_curr, h_max);
    	for (int i = 0; i < verticalCuts.size(); i++) {
    		w_max = max(verticalCuts[i] - w_curr, w_max);
            w_curr = verticalCuts[i];
    	}
    	w_max = max(verticalCuts[verticalCuts.size() - 1] - w_curr, w_max);
    	long area = h_max * w_max;
    	return (int) (area % mod);
    }
};