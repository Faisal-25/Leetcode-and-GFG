class Solution {
    public int[] searchRange(int[] arr, int target) {
        int lo = 0;
        int ans2 = -1;
        int hi = arr.length - 1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]<target){
                lo=mid+1;
            }
            else if(arr[mid]>target){
                hi = mid-1;
            }
            else{
                ans2 = mid;
                lo = mid+1;
            }
        }
        lo=0;
        hi = arr.length - 1;
        int ans1 = -1;
         while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]<target){
                lo=mid+1;
            }
            else if(arr[mid]>target){
                hi = mid-1;
            }
            else{
                ans1 = mid;
                hi = mid-1;
            }
        }
        return new int[]{ans1,ans2};
    }
}