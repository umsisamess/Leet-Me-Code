class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i=0;i<time.size();i++){
            mp[time[i]%60]++;
        }
        for(int i=0;i<=30;i++){
            if(mp[i]==0){
                continue;
            }
            if(i==0 || i==30){
                sum += mp[i]*(mp[i]-1)/2;
            }
            else{
                sum += mp[i]*mp[60-i];
            }
        }
        return sum;
    }
};