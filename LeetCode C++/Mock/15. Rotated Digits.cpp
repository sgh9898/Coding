class Solution {
public:
    int rotatedDigits(int n) {
        int help[] = {1,1,2,0,0,2,2,0,1,2};
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int s = 1;
            int p = i;
            while(p){
                s *= help[p % 10];
                p /= 10;
            }
            if( s>= 2)ans++;
        }
        return ans;
    }
};
