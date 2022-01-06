class Solution {
public:
    // static bool comp(vector<int> v1, vector<int> v2){
    //     return v1[1]<v2[1];
    // }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        set<int> st;
        unordered_map<int,int> mp;
        for(int i=0;i<trips.size();i++){
           mp[trips[i][1]] += trips[i][0];
            mp[trips[i][2]] -= trips[i][0];
            st.insert(trips[i][1]);
            st.insert(trips[i][2]);
        }
        
        int sum = 0;
        for(auto i : st){
            sum += mp[i];
            if(sum>capacity){
                return false;
            }
        }
        
        return true;
    }
};