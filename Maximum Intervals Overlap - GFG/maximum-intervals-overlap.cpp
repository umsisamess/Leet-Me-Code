// { Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N){
	   sort(Entry,Entry+N);
	   sort(Exit,Exit+N);
	   int count = 0;
	   int max_count = 0;
	   int max_time = 0;
	   int left1 = 0;
	   int left2 = 0;
	   while(left1<N && left2<N){
	       if(Entry[left1]<=Exit[left2]){
	           count += 1;
	           if(max_count<count){
	               max_count = count;
	               max_time = Entry[left1];
	           }
	           left1++;
	       }else{
	           count--;
	           left2++;
	       }
	   }
	   
	   return {max_count,max_time};
	   
	}

};

// { Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends