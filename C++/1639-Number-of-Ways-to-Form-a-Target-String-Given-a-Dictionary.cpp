class Solution {
public:
    int dp[1001][1001];
    int mod  = 1e9 +7;
    int rec(int idx1,int idx2,string &target,vector<vector<int>> &adj){
        if(idx2>=target.size()) return 1;
        if(idx1>=adj.size()) return 0;
        if(dp[idx1][idx2] !=-1) return dp[idx1][idx2];
        // take
        if(adj[idx1][target[idx2]-'a']>0) {
            long long a = (1ll * adj[idx1][target[idx2]-'a'] * rec(idx1 +1,idx2+1,target,adj)) % mod;
            long long b = rec(idx1 + 1, idx2, target ,adj) % mod;
            return dp[idx1][idx2] = (a + b) % mod;
        }
        return dp[idx1][idx2] = rec(idx1 + 1, idx2, target ,adj) % mod;
    }
    int numWays(vector<string>& words, string target) {
        int n= words.size();
        vector<vector<int>> adj(words[0].size(),vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(int j =0;j<words[i].size();j++)
                adj[j][words[i][j] - 'a']++;
        }
        memset(dp,-1,sizeof(dp));
        return rec(0,0,target,adj);
    }
};
