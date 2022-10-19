class Solution {
public:
    #define pi pair<int, pair<int, int>>
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue< pi ,vector<pi> ,greater<pi> > pq;
        int mex=INT_MIN,men=INT_MAX;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            mex=max(mex,nums[i][0]);
            men=min(men,nums[i][0]);
        }
        int a=mex,b=men;
        while(pq.size()>0){
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(col + 1<nums[row].size()){
                int new_element=nums[row][col+1];
                pq.push({nums[row][col+1],{row,col+1}});
                mex=max(mex,new_element);
                men=pq.top().first;
                if(mex-men<a-b){
                    a=mex;
                    b=men;
                }
            }
            else break;
        }
        return {b,a};
    }
};
