class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
    	HashSet<String> dna = new HashSet<>();
        HashSet<String> res = new HashSet<>();
        int lt = 0, rt = 10;

        while (rt <= s.length()) {
            String temp = s.substring(lt, rt);
            if (dna.contains(temp)) {
                res.add(temp);
            } else {
                dna.add(temp);
            }
            lt++;
            rt++;
        }

        return new ArrayList<>(res);
    }
}