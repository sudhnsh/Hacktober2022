

// Leetcode 1200
// Link : https://leetcode.com/problems/minimum-absolute-difference/
// Minimum Absolute Difference


#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        sort(a.begin(),a.end());
        int mnd=INT_MAX;
        int n=a.size();
        for(int i=0; i<n-1; i++)
            mnd=min(mnd,a[i+1]-a[i]);
        vector<vector<int>> ans;
        for(int i=0; i<n-1; i++)
        {
            if(a[i+1]-a[i]==mnd) ans.push_back({a[i],a[i+1]});
        }
        return ans;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long int



int main()
{
    vector<int> a{1, 2, 3, 4,};
    
    vector<vector<int>> ans = minimumAbsDifference(a);
    
    return 0;
}