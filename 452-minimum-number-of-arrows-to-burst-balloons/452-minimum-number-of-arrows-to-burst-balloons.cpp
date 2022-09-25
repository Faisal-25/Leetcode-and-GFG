class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points),[](const vector<int>& v1, const vector<int> &v2 ){
            if(v1[0] == v2[0]){
                return v1[1]>v2[1];
            }
            return v1[0]<v2[0];
        });
      
        int prevMin = points[0][1];
        int count = 1;
        for(int i = 1;i<points.size();i++){
            if(prevMin <points[i][0]){
                count++;
                prevMin = points[i][1];
            }
            prevMin = min(points[i][1], prevMin);
        }
return count;
    }
};