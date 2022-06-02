class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<vector<int>> pq;
        
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]){
                pq.push({freq[nums[i]],nums[i]});
                freq[nums[i]] = 0;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            vector<int> top = pq.top();
            pq.pop();
            ans.push_back(top[1]);
        }
        
        return ans;
    }
};