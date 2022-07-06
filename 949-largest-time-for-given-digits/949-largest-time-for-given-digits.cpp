class Solution {
public:
    bool check(string& ans, int x,unordered_map<int,int>& mp){
        for(int i=x;i>=0;i--){
            if(mp[i]>0){
                mp[i]--;
                ans += to_string(i);
                return true;
            }
        }
        return false;
    }
    
    bool calc(string& ans, int i, unordered_map<int,int>& mp){
        if(mp[i]>0){
            ans += to_string(i);
        }else{
            return false;
        }
        mp[i]--;
        check(ans,9,mp);
        ans += ":";
        bool ok = check(ans,5,mp);
        if(ok==false){
            return false;
        }else{
            check(ans,9,mp);
        }
        return true;
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_map<int,int> mp1;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        mp1 = mp;
        
        string ans = "";
        int yes1 = 1,yes2=1,yes3=1;
        if(mp[2]>0){
            ans += "2";
            mp[2]--;
            bool ok = check(ans,3,mp);
            
            if(ok==false){
                yes1 = 0;
            }else{
                ans += ":";
                bool ok1 = check(ans,5,mp);
                if(ok1==false){
                    yes1 = 0;
                }else{
                    check(ans,9,mp);
                }
            }
        }else{
            yes1 = 0;
        }
        
        if(yes1==0){
            mp = mp1;
            ans = "";
            if(calc(ans,1,mp)==false) yes2 = 0;
        }
        
        if(yes1==0 && yes2==0){
            mp = mp1;
            ans = "";
            if(calc(ans,0,mp)==false) yes3 = 0;
        }
        
        if(yes1==0 && yes2==0 && yes3==0){
            return "";
        }else{
            return ans;
        }
    }
};