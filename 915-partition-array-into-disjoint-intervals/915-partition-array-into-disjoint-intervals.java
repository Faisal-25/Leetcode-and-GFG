class Solution {
    public int partitionDisjoint(int[] nums) {
        int n = nums.length;
        int [] rightMin = new int[n];
        int [] leftMax = new int[n];
        int k = n-1;
        for(int i = 0;i<n;i++){
            if(i == 0) leftMax[i] = nums[i];
            else leftMax[i] = Math.max(nums[i],leftMax[i-1]);
            if(k == n-1) rightMin[k] = nums[k];
            else rightMin[k] = Math.min(rightMin[k+1],nums[k]);
            k--;
        }
        for(int i = 0;i<n-1;i++){
            if(leftMax[i]<=rightMin[i+1]){
                return i+1;
            }
        } 
        return n-1;
    }
}