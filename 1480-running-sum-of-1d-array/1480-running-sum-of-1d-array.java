class Solution {
    public int[] runningSum(int[] nums) {
        int [] prefix = new int[nums.length];
        prefix[0] = nums[0];
        int n= nums.length;
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        return prefix;
    }
}