class Solution {
public:
    int ok(vector<vector<int>>& mat,int n,int m,int k,int mid,int r,int sum){
        if(sum>mid) return 0;
        if(r==n) return 1;
        int ans=0;
        for(int i=0;i<m;i++){
            int cnt=ok(mat,n,m,k-ans,mid,r+1,sum+mat[r][i]);
            ans+=cnt;
            if(ans>k || cnt==0) break;
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        int lo=0,hi=5000*40*40,ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int cnt=ok(mat,n,m,k,mid,0,0);
            if(cnt>=k){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};
