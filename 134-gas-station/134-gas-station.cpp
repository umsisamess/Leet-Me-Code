class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i,j;
        int n = gas.size();
        int total = 0;
        int sum = 0;
        int res = 0;
        for(i=0;i<n;i++){
            if(sum>=0){
                sum += gas[i] - cost[i];
            }
            else{
                total += sum;
                sum = 0;
                sum += gas[i] - cost[i];
                res = i;
            }
        }
        if(total+sum>=0){
            return res;
        }
        else{
            return -1;
        }
        
    }
};