class Solution {
    public List<Boolean> areConnected(int n, int threshold, int[][] queries) {
        List<Boolean> res = new ArrayList<>();
        int[] p = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            p[i] = i;
        }
        for (int i = threshold; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!connected(i, j, p) &&
                    gcd(i, j, threshold)) {
                    union(i, j, p);
                }
            }
        }
        
        for (int[] q : queries) {
            res.add(connected(q[0], q[1], p));
        }
        return res;
    }
    
    private boolean connected(int i, int j, int[] p) {
        return find(i, p) == find(j, p);
    }
    
    private void union(int i, int j, int[] p) {
        int iRoot = find(i, p);
        int jRoot = find(j, p);
        if (iRoot != jRoot) {
            p[iRoot] = jRoot;
        }
    }
    
    private int find(int i, int[] p) {
        if (p[i] != i) {
            p[i] = find(p[i], p);
        }
        return p[i];
    }
    
    private boolean gcd(int a, int b, int th) {
        if (b == 0 && a > th) {
            return true;
        }
        if (b < th) {
            return false;
        }
        return gcd(b, a % b, th);
    }
}
