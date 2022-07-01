class Solution {
public:
  static bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1]>v2[1];
}
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),sortcol);
        int ans = 0;
        int count = 0;
        for(vector<int> v:boxTypes){
            int boxType = v[0];
            int units = v[1];
            int i = 1;
            while(i<=boxType && count<truckSize){
                ans+=units;
                i++;
                count++;
            }
        }
        return ans;
        
    }
};