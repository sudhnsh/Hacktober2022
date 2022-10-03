

// Leetcode - 999
// Link : https://leetcode.com/problems/available-captures-for-rook/
// Available Captures for Rook

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int numRookCaptures(vector<vector<char>>& brd) {
        int ans=0;
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                if(brd[i][j]=='R')
                {
                    for(int k=j+1;k<8;k++)
                    {
                        if(brd[i][k]=='B') break;
                        if(brd[i][k]=='p')
                        {
                            ans++; break;
                        }
                    }
                    for(int k=j-1;k>=0;k--)
                    {
                        if(brd[i][k]=='B') break;
                        if(brd[i][k]=='p')
                        {
                            ans++; break;
                        }
                    }
                    for(int k=i-1;k>=0;k--)
                    {
                        if(brd[k][j]=='B') break;
                        if(brd[k][j]=='p')
                        {
                            ans++; break;
                        }
                    }
                    for(int k=i+1;k<8;k++)
                    {
                        if(brd[k][j]=='B') break;
                        if(brd[k][j]=='p')
                        {
                            ans++; break;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
    
int main()
{
    
    
    return 0;
}