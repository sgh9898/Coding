class Solution {
    public boolean isPalindrome(String s) {
        int lt = 0, rt = s.length()-1;
        while (lt <= rt) {
            while (!Character.isLetterOrDigit(s.charAt(lt))) {
                lt++;
                if (lt >= s.length())   return true;
            }
            char temp_lt = Character.toLowerCase(s.charAt(lt));
            lt++;

            while (!Character.isLetterOrDigit(s.charAt(rt))) {
                rt--;
                if (rt < 0) return true;
            }
            char temp_rt = Character.toLowerCase(s.charAt(rt));
            rt--;
            if (temp_lt != temp_rt) {
                return false;
            }
        }
        return true;
    }
}
