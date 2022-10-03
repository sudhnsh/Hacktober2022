

// Leetcode 1380
// Link : https://leetcode.com/problems/lucky-numbers-in-a-matrix/
//Lucky Numbers in a Matrix

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> ans;
        unordered_set<int> st;
        for(int i=0; i<m; i++)
        {
            int mn=INT_MAX;
            for(int j=0; j<n; j++)
            {
                mn=min(mn, mat[i][j]);
            }
            st.insert(mn);
        }
        for(int i=0; i<n; i++)
        {
            int mx=INT_MIN;
            for(int j=0; j<m; j++)
            {
                mx=max(mx, mat[j][i]);
            }
            if(st.find(mx)!=st.end()) ans.push_back(mx);
        }
        return ans;
    }
};

