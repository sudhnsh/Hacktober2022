class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++)
                matrix[i][j]+=matrix[i][j-1];
        }
        int ans=INT_MIN;
        for(int c1=0;c1<m;c1++){
            for(int c2=c1;c2<m;c2++){
                multiset<int> me;
                int sum=0;
                for(int row=0;row<n;row++){
                    sum+=matrix[row][c2]-(c1>0?matrix[row][c1-1]:0);
                    if(sum<=k) ans=max(sum,ans); 
                    auto it=me.lower_bound(sum-k);
                    if(it!=me.end() and (sum-*it)<=k) ans=max(ans,sum-*it);
                    me.insert(sum);
                }
                
            }
        }
        return ans;
    }
};
