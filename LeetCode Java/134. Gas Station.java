class Solution {
   public int canCompleteCircuit(int[] gas, int[] cost) {
       int n = gas.length;
       int sum = 0;
       int min = 0; 
       int idx = 0;
       for (int i = 0; i < n; i++) {
           sum += gas[i] - cost[i];
           if (sum < min) {
               min = sum;
               idx = i + 1;
           }
       }
       return sum < 0 ? -1 : idx;
   }
}