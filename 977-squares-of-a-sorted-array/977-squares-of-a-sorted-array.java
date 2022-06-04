class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int [] arr = new int[nums.length];
        int lo = 0;
        int hi = n-1;
        int idx = n-1;
        while(lo<=hi){
            if(Math.abs(nums[lo])>Math.abs(nums[hi])){
                arr[idx] = nums[lo]*nums[lo];
                idx--;
                lo++;
            }
            else{
                arr[idx] = nums[hi]*nums[hi];
                hi--;
                idx--;
            }
            
        }
        return arr;
    }
}