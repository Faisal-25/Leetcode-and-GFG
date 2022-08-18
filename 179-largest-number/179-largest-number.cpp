class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string* arr = new string[nums.size()];
        int n = nums.size();
        for(int i = 0;i<n;i++){
            arr[i] = to_string(nums[i]);
        }
        sort(arr,arr+n,[](const string &s1, const string &s2){
            string c1 = s1+s2;
            string c2 = s2+s1;
            return c1>c2;
        });
        if(arr[0] == "0")return "0";
        string ans = "";
        for(int i = 0;i<n;i++){
            ans+=arr[i];
        }
        return ans;
    }
};