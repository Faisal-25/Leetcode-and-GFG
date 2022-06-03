class NumArray {
    int [] prefix = new int[0];
    public NumArray(int[] nums) {
        this.prefix = new int[nums.length+1];
        prefix[0] = 0;
        prefix[1]  = nums[0];
        int n = nums.length;
        for(int i = 2;i<=n;i++){
            prefix[i] = prefix[i-1]+nums[i-1];
        }
        
    }
    
    public int sumRange(int left, int right) {
        return prefix[right+1]-prefix[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */