class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int> diff;
        priority_queue<int> pq;
        int n = heights.size();
        int pqsum = 0;
        int i = 1;
        int ladder_count = 0;
        while(i<n){
            if(heights[i]-heights[i-1]>0){
                pq.push(heights[i]-heights[i-1]);
                pqsum += heights[i]-heights[i-1];
                if(pqsum>bricks){
                    if(ladder_count==ladders){
                        break;
                    }else{
                        ladder_count++;
                        pqsum -= pq.top();
                        pq.pop();
                    }
                }
            }
            i++;
        }
        return i-1;
    }
};