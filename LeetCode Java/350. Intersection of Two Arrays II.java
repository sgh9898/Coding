class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();

        // build a hashmap
        for (int n1 : nums1) {
            hash.put(n1, hash.getOrDefault(n1,0)+1);
        }

        List<Integer> res = new ArrayList<>();
        for (int n2 : nums2) {
            // intersection
            if (hash.containsKey(n2)) {
                int cnt = hash.get(n2);
                if (cnt > 0) {
                    res.add(n2);
                    hash.put(n2, cnt-1);
                }
            }
        }

        int[] out = new int[res.size()];
        for (int i = 0; i < out.length; i++) {
            out[i] = res.get(i);
        }
        return out;
    }
}
