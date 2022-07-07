class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int a = -1, b = -1, counta = 0, countb = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(counta==0){
                a = fruits[i];
            }
            if(countb==0 && a!=fruits[i]){
                b = fruits[i];
            }
            if(fruits[i]==a){
                counta++;
            }else if(fruits[i]==b){
                countb++;
            }else{
                int j = i-1;
                counta = 0;
                while(j>=0 && fruits[j]==fruits[i-1]){
                    counta++;
                    j--;
                }
                a = fruits[i-1];
                b = fruits[i];
                countb = 1;
            }
            ans = max(ans,counta+countb);
        }
        return ans;
    }
};