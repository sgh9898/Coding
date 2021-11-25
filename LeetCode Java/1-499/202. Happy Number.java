class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> set = new HashSet<Integer>();
        int res;

        while (!set.contains(n)) {  // avoid endless loops
            set.add(n);
            res = 0;
            while (n > 0) {
                res += Math.pow(n%10,2);
                n /= 10;
            }
            if (res == 1) {
                return true;
            } else {
                n = res;
            }
        }
        return false;
    }
}
