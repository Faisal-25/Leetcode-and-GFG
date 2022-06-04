class Solution {
    public int maxChunksToSorted(int[] arr) {
        int chunks = 0;
        int n = arr.length;
        int max = Integer.MIN_VALUE,j = 0;
        while(j<arr.length){
            max = Math.max(max, arr[j]);
            if(j == max){
                chunks++;
            }
            j++;
        }
        return chunks;
    }
}