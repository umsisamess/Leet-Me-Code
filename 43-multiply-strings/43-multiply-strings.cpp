class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        int l1 = num1.size();
        int l2 = num2.size();
        vector<int> sum(l1+l2,0);

        for(int i=l1-1;i>=0;i--){
            for(int j=l2-1;j>=0;j--){
                sum[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                sum[i+j] += sum[i+j+1]/10;
                sum[i+j+1] %= 10;
            }
        }
        
        string ans = "";
        int i = 0;
        while(sum[i]==0){
            i++;
        }
        while(i<l1+l2){
            ans += ('0'+sum[i]);
            i++;
        }
        return ans;
    }
};