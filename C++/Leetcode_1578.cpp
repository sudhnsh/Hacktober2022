
// Leetcode - 1578
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
// Find All Numbers Disappeared in an Array

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<int> findDisappearedNumbers(vector<int>& a) {
    
        vector<int> ans;
        int n=a.size();
        for(int i=0; i<n; i++)
        {
            int temp=abs(a[i])-1;
            a[temp]=-abs(a[temp]);
        }
        for(int i=0; i<n; i++) if(a[i]>0) ans.push_back(i+1);
        return ans;
    }

int main()
{
    
    
    return 0;
}