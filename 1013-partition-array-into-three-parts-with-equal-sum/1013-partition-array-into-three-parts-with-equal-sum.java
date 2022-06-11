class Solution {
    public boolean canThreePartsEqualSum(int[] arr) {
        int n = arr.length;
        int sum = 0;
        int total = 0;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%3!=0)return false;
        int count = 0;
        for(int i = 0;i<n;i++){
            total+=arr[i];
            if(total == sum/3){
                count++;
                total = 0;
            }
        }
        return count>=3;
    }
}