class Solution {
public:
    int checkHours(vector<int>& piles, int m){
        int sum = 0;
        for(auto i:piles){
            sum += ceil(1.0*i/m);
        }
        return sum;
    }
    
    int findSpeed(int l, int r,vector<int>& piles, int& h ){
        int m = l/2+r/2+(l%2+r%2)/2;
        if(l==1 && r==2) m = 2;
        if(m==1) return 1;
        int hours = checkHours(piles,m);
        int hours1 = checkHours(piles,m-1);
        if(hours1>h){
            if(hours<=h) return m;
            else return findSpeed(m+1,r,piles,h);
        }
        else{
            return findSpeed(l,m-1,piles,h);
        }
    }
        
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int l = 1, r = piles[piles.size()-1];
        return findSpeed(l,r,piles,h);
    }
};