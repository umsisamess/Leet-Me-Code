class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxiy = 0;
        sort(verticalCuts.begin(),verticalCuts.end());
        verticalCuts.push_back(w);
        for(int i=0;i<verticalCuts.size();i++){
            if(i==0) maxiy = max(maxiy,verticalCuts[i]-0);
            else maxiy = max(maxiy,verticalCuts[i]-verticalCuts[i-1]);
        }
        
        int maxix = 0;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        horizontalCuts.push_back(h);
        for(int i=0;i<horizontalCuts.size();i++){
            if(i==0) maxix = max(maxix,horizontalCuts[i]-0);
            else maxix = max(maxix,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        long long int y = maxix;
        y *= maxiy;
        y %= 1000000007;
        return (int)y;
    }
};