class Solution {
    public int maximumProduct(int[] nums) {
        String str = "370902199704291552";
        if (str.length() >= 18) {
            str = str.substring(0, 6) + "********" + str.substring(str.length() - 4);
        }
        System.out.println(str);
        return 0;
    }
}
