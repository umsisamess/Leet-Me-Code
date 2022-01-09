class Solution {
public:
    void followInstruction(string s,int& startx, int& starty, int& x, int& y){
        for(int i=0;i<s.length();i++){
            if(s[i]=='G'){
                startx += x;
                starty += y;
            }
            else if(s[i]=='L'){
                int t = x;
                x = -y;
                y = t;
            }
            else{
                int t = y;
                y = -x;
                x = t;
            }
        }
    }
    
    bool isRobotBounded(string instructions) {
        int startx=0, starty=0;
        int n = instructions.length();
        int x = 1, y = 0;
        for(int i=0;i<4;i++){
           followInstruction(instructions,startx,starty,x,y); 
        }
        if(startx==0 && starty==0){
            return true;
        }
        else{
            return false;
        }
    }
};