// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    
    int maxMeetings(int start[], int end[], int n){
        if(n==0) return 0;
        
        vector<vector<int>> act;
        for(int i=0;i<n;i++){
            act.push_back({end[i],start[i]});
        }
        
        sort(act.begin(),act.end());
        
        int ans = 1;
        int endd = act[0][0];
        for(int i=1;i<n;i++){
            if(act[i][1]>endd){
                ans += 1;
                endd = act[i][0];
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends