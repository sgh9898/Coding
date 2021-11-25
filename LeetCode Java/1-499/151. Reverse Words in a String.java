class Solution {
    public String reverseWords(String s) {
    	s = s.trim();
    	List<String> words = Arrays.asList(s.split("\\s+"));
    	Collections.reverse(words);
    	return String.join(" ", words);
    }
}