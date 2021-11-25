class Solution {
    public int countPrimes(int n) {
        if (n <= 2) return 0;
        boolean[] primes = new boolean[n];
        int cnt = 0;
        primes[0] = true;
        for (int num = 2; num < n; num++) {
            if (primes[num-1] == false) cnt++;
            for (int i = num-1; i < n; i +=num) {
                primes[i] = true;
            }
        }
        return cnt;
}
