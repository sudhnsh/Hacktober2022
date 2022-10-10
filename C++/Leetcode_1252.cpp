

// Leetcode - 1252
// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/
// Cells with Odd Values in a Matrix

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int oddCells(int m, int n, vector<vector<int>>& ind) {
        
        unordered_map<int,int> r, c;
        for(auto v:ind)
        {
            r[v[0]]++; 
            c[v[1]]++; 
        }
        int ans=0;
        int orcnt=0, ercnt=0, occnt=0, eccnt=0;
        for(auto pr:r) 
        {
            if(pr.second%2) orcnt++;
            else ercnt++;
        }
        for(auto pr:c) 
        {
            if(pr.second%2) occnt++;
            else eccnt++;
        }
        ans += orcnt*n;
        ans += (m-r.size())*occnt;
        ans -= orcnt*occnt;
        ans += ercnt*occnt;
        return ans;
    }
    
int main()
{
    
    
    return 0;
}