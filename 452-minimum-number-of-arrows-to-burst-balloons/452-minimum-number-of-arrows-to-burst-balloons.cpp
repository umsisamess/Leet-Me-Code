class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        int a = n-1;
        int count = n;
        for(int i=n-2;i>=0;i--){
            if(points[i][0]==points[a][0]){
                count-=1;
            }
            else{
                if(points[i][1]<points[a][0]){
                    a = i;
                }
                else{
                    count -= 1;
                }
            }
        }
        return count;
    }
};