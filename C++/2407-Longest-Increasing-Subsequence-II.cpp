class Solution {
public:
    vector<int> seg;
    vector<int> ar;
    int N = 1e5 + 10;
    int query(int st,int ed,int t,int l,int r){
        if(st >r || ed<l) return INT_MIN;
        if(st>=l and ed<=r) return seg[t];
        int mid=(st +ed)/2;
        return max(query(st,mid,t*2,l,r),query(mid+1,ed,t*2+1,l,r));
    }
    void update(int st,int ed,int t,int idx,int val){
        if(st > ed) return;
        if(st==ed){
            if(st!=idx) return;
            seg[t]=val;
            ar[st] = val;
            return;
        }
        int mid =(st +ed)/2;
        if(idx <= mid) update(st,mid,2*t,idx,val);
        else update(mid+1,ed,t*2 + 1,idx,val);
        seg[t] = max(seg[2*t], seg[2*t + 1]);
    }               
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        seg=vector<int>(4 *N + 10,0);
        ar= vector<int>(N,0);
        for(int i=0;i<n;i++){
            int lb=max(0,nums[i]-k);
            int get_max = query(0,N,1,lb,max(0,nums[i]-1));
            if(ar[nums[i]] < get_max + 1) update(0,N,1,nums[i],get_max + 1);
        }
        return *max_element(ar.begin(),ar.end());
    }
};
