class Solution {
public:
    void generateIt(int left, int right, string tillNow, vector<string>& parenthesis){
        if(right==0){
            parenthesis.push_back(tillNow);
            return;
        }
        if(left>0){
            generateIt(left-1,right,tillNow+"(",parenthesis);
        }
        if(right>left){
            generateIt(left,right-1,tillNow+")",parenthesis);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        generateIt(n,n,"",parenthesis);
        return parenthesis;
    }
};