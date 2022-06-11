class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        int n = nums.length;
        int total = 0;
        for(int i = 0;i<n;i++){
            total+=nums[i];
        }
      Arrays.sort(nums);
        int sum = 0;
        List<Integer> ans = new LinkedList<>();
        for(int i = n-1;i>=0;i--){
            ans.add(nums[i]);
            sum+=nums[i];
            if(sum>total/2){
                return ans;
            }
        }
        return new LinkedList<>();
    }
}