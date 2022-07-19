class Solution {
    int maxElement(int[]nums){
        int max = -1;
        for(int i = 0;i<nums.length;i++){
            max = Math.max(nums[i],max);
        }
        return max;
    }
    int sumAfterDivision(int []nums,int div){
        int sum = 0;
        for(int i = 0;i<nums.length;i++){
            sum+=nums[i]/div;
            if(nums[i]%div!=0){
                ++sum;
            }
        }
        return sum;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int lo = 1;
        int hi = maxElement(nums);
        int ans = hi;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(sumAfterDivision(nums,mid)<=threshold){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
}